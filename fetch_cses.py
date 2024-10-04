#!/usr/bin/env python3

import argparse
import logging
import re
import subprocess
import sys

import requests
from bs4 import BeautifulSoup


def problem_name_to_snake_case(text: str) -> str:
    result = []
    for i in range(len(text)):
        if text[i] == ' ':
            continue
        ch = text[i]
        if i > 0 and text[i - 1] == ' ' and ch.lower():
            ch = ch.upper()
        if ch.isupper() and i > 0 and (text[i - 1].islower() or text[i - 1] == ' '):
            result.append('_')
        result.append(ch.lower())
    return ''.join(result)

def add_opts(parser: argparse.ArgumentParser) -> None:
    parser.add_argument(
        'id',
        type=int,
        help='Problem id',
    )
    parser.add_argument(
        '-c',
        '--cpp',
        help='Whether to create cpp file',
        action='store_true',
    )
    parser.add_argument(
        '-s',
        '--subl',
        help='Open created cpp file with Sublime Text',
        action='store_true',
    )
    parser.add_argument(
        '-v',
        '--code',
        help='Open created cpp file with VS Code',
        action='store_true',
    )
    

def main():
    parser = argparse.ArgumentParser(
        description='Get CSES problem title, input, and output.',
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )
    add_opts(parser)
    args = parser.parse_args()

    logger = logging.getLogger('create_cses')
    logging.basicConfig(level=logging.INFO, format='[%(levelname)s] %(message)s')

    problem_link = f'https://cses.fi/problemset/task/{args.id}'
    try:
        response = requests.get(problem_link)
    except requests.exceptions.RequestException as e:
        raise Exception(f'Could not get problem with id {problem_link}: {e}')

    soup = BeautifulSoup(response.content, 'html.parser')

    problem_name = soup.select_one('.title-block h1')
    if problem_name is None:
        raise Exception(f'Could not resolve problem name from {problem_link}')
    problem_name = problem_name.text.strip()
    logger.info(f'Found problem: {problem_name}')
    problem_name = problem_name_to_snake_case(problem_name)

    example_elements = soup.find_all(id=re.compile(r'example\d*'))
    if example_elements is None:
        raise Exception(f'Could not resolve example from {problem_link}')

    for idx, example_element in enumerate(example_elements):
        input_label_element = example_element.find_next_sibling('p', string="Input:")
        input_element = input_label_element.find_next_sibling('pre') if input_label_element else None
        if input_element is not None:
            input_text = input_element.text.strip()
            input_file_name = f'{idx + 1}.in'
            with open(input_file_name, 'w', encoding='utf-8') as f:
                f.write(input_text)
            total_input_len = len(input_text.split("\n"))
            logger.info(f'Wrote {total_input_len} line(s) to {input_file_name}')

        output_label_element = example_element.find_next_sibling('p', string="Output:")
        output_element = output_label_element.find_next_sibling('pre') if output_label_element else None
        if output_element is not None:
            output_text = output_element.text.strip()
            output_file_name = f'{idx + 1}.ans'
            with open(output_file_name, 'w', encoding='utf-8') as f:
                f.write(output_text)
            total_output_len = len(output_text.split("\n"))
            logger.info(f'Wrote {total_output_len} line(s) to {output_file_name}')

    if args.cpp:
        file_name = f'cses_{args.id}_{problem_name}'
        # IMPORTANT: replace the command below with your template generator
        # if you have one (the command is `gen` in my case).
        subprocess.run(['gen', file_name])
        if args.subl:
            subprocess.run(['subl', f'{file_name}.cpp'])
        elif args.code:
            subprocess.run(['code', f'{file_name}.cpp'])


if __name__ == '__main__':
    sys.exit(main())
