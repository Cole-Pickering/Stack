#include "postfixCalc.hpp"
#include "LLStack.hpp"

unsigned postfixCalculator(const std::vector<std::string> & entries)
{
	int sec;
	LLStack<int> calcStack;
	for (int i =0; i<entries.size();i++){
		if (entries[i] == "*"){
			if (calcStack.size() < 2){
				throw CannotEvaluateException("Stack Too Small");
			}
			sec = calcStack.top();
			calcStack.pop();
			sec = calcStack.top() * sec;
			calcStack.pop();
			calcStack.push(sec);
		}
		else if (entries[i] == "/"){
			if (calcStack.size() < 2){
				throw CannotEvaluateException("Stack Too Small");
			}
			sec = calcStack.top();
			calcStack.pop();
			sec = calcStack.top() / sec;
			calcStack.pop();
			calcStack.push(sec);
		}
		else if (entries[i] == "+"){
			if (calcStack.size() < 2){
				throw CannotEvaluateException("Stack Too Small");
			}
			sec = calcStack.top();
			calcStack.pop();
			sec = calcStack.top() + sec;
			calcStack.pop();
			calcStack.push(sec);
		}
		else if (entries[i] == "-"){
			if (calcStack.size() < 2){
				throw CannotEvaluateException("Stack Too Small");
			}
			sec = calcStack.top();
			calcStack.pop();
			sec = calcStack.top() - sec;
			calcStack.pop();
			calcStack.push(sec);
		}
		else{
			calcStack.push(std::stoul(entries[i]));
		}
	}
	if (calcStack.size() == 1){
		return calcStack.top();
	}
	else{
		throw CannotEvaluateException("Stack Too Small");
	}
}

