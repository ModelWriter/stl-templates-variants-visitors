// ============================================================================
// Project: Bracket-matching example of stack usage             File: token.hpp
// Author:  Michael and Alice Fischer                   Copyright: January 2009
// Modified February 2016
// Modified September 2016 by Michael Fischer
// ============================================================================
#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "tools.hpp"

enum BracketType { BKT_SQ, BKT_RND, BKT_CURLY, BKT_ANGLE, BKT_NONE };
enum TokenSense { SENSE_LEFT, SENSE_RIGHT };

class Token {
  public:
    static int nextID;

  private:
    int id = nextID++;
    BracketType type = BKT_NONE;
    TokenSense sense = SENSE_LEFT;
    char ch = '\0';
    void classify(char ch);
    int* dynarray = nullptr;
    void protectFromDeletion() { dynarray = nullptr; }

  public:
    explicit Token(char ch); // additional constructor
    Token() {
        cerr << "Default constructor for token " << id << " called\n";
        dynarray = nullptr;
    }                                 // default constructor
    Token(const Token& rhs) = delete; // default copy constructor
    Token(Token&& rhs) noexcept {
        type = rhs.type;
        sense = rhs.sense;
        ch = rhs.ch;
        dynarray = rhs.dynarray;
        cerr << "Move constructor for token " << id << " called\n";
        rhs.protectFromDeletion();
    }
    Token& operator=(const Token&) = delete; // default copy assignment
    Token& operator=(Token&& rhs) noexcept { // redefined move assignment
        type = rhs.type;
        sense = rhs.sense;
        ch = rhs.ch;
        if (dynarray != nullptr) {
            delete[] dynarray;
        }
        dynarray = rhs.dynarray;
        cerr << "Move assignment for token " << id << " called\n";
        rhs.protectFromDeletion();
        return *this;
    }

    // Token() : type(), sense(), ch() {}
    ~Token() {
        cerr << "Destructor for token " << id << " called\n";
        delete[] dynarray;
    }
    ostream& print(ostream& out) const {
        return out << "token " << id << " " << ch;
    }
    [[nodiscard]] BracketType getType() const { return type; }
    [[nodiscard]] TokenSense getSense() const { return sense; }
};

inline ostream& operator<<(ostream& out, const Token& t) {
    return t.print(out);
}
#endif // TOKEN_HPP
