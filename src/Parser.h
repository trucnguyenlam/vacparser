#pragma once

#include "Models.h"
#include "Tokens.h"
#include <exception>

namespace Parser {
class ParserError : public std::exception {
  private:
    std::string _message;
  public:
    ParserError(const std::string &msg = "");
    virtual const char* what() const noexcept override;
};


class HandParser {
  public:
    HandParser(std::vector<Token *> tokens);
    ~HandParser();

    void parse(void);
    ModelPtr getPolicy(void) const;

  private:
    // Helper method
    void r_start(void);

    void r_user(void);
    void user_element(void);
    void r_attr(void);
    void attr_element(void);
    void r_init(void);

    void init_element(void);
    void init_assignment(UserPtr user);
    void r_rules(void);
    void rule_element(void);
    Expr primaryExpression(std::map<std::string, int>& , int& );
    Expr unaryExpression(std::map<std::string, int>& , int& );
    Expr equalityExpression(std::map<std::string, int>& , int& );
    Expr andExpression(std::map<std::string, int>& , int& );
    Expr orExpression(std::map<std::string, int>& , int& );
    Expr implyExpression(std::map<std::string, int>& , int& );
    Expr conditionalExpression(std::map<std::string, int>& , int& );
    Expr expression(std::map<std::string, int>& , int& );
    void normal_assignment(RulePtr ruleptr,  std::map<std::string, int>& , std::string & );
    void r_query(void);
    void query_normal_assignment(void);
    bool match(TokenType type);
    Token* consume(TokenType type, std::string message);
    void checkConsume(TokenType type, std::string message);
    bool check(TokenType type);
    bool isAtEnd(void);
    Token * previous(void) const;
    Token * advance(void);
    Token * peek(void) const;

    ModelPtr vac_model;
    std::vector<Token *> tokens;
    int current;

};
}