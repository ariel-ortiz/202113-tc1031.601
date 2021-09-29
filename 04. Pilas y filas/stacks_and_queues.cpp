#include <cctype>
#include <queue>
#include <regex>
#include <stack>
#include <stdexcept>
#include <string>
#include "stacks_and_queues.h"

std::queue<std::string> split(const std::string& input)
{
    std::regex exp(R"((\d+)|(\s)|(.))");
    std::smatch match;
    std::string next_input = input;
    std::queue<std::string> result;

    while(regex_search(next_input, match, exp)) {
        if (match[2] == "") {
            result.push(match[0]);
        }
        next_input = match.suffix();
    }

    return result;
}

int postfix_evaluation(const std::string& expr)
{
    std::queue<std::string> tokens = split(expr);
    std::stack<int> eval_stack;

    while (not tokens.empty()) {
        std::string element = tokens.front();
        tokens.pop();

        if (isdigit(element[0])) {
            eval_stack.push(stoi(element));

        } else if (element == "+" or element == "-"
            or element == "*" or element == "/") {
            if (eval_stack.size() < 2) {
                throw std::invalid_argument(expr
                    + ": too few operands for operator " + element);
            }
            int b = eval_stack.top();
            eval_stack.pop();
            int a = eval_stack.top();
            eval_stack.pop();

            int result;

            if (element == "+") {
                result = a + b;
            } else if (element == "-") {
                result = a - b;
            } else if (element == "*") {
                result = a * b;
            } else {
                result = a / b;
            }
            eval_stack.push(result);

        } else {
            throw std::invalid_argument(expr
                + ": unknown symbol " + element);
        }
    }

    if (eval_stack.size() == 1) {
        return eval_stack.top();
    } else {
        throw std::invalid_argument(expr
            + ": missing one or more operators");
    }
}

bool balanced_brackets(const std::string& expr)
{
    return false;
}
