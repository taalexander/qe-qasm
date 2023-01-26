/* -*- coding: utf-8 -*-
 *
 * Copyright 2021 IBM RESEARCH. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * =============================================================================
 */

#ifndef __QASM_AST_IF_STATEMENT_BUILDER_H
#define __QASM_AST_IF_STATEMENT_BUILDER_H

#include <qasm/AST/ASTIfConditionals.h>
#include <qasm/AST/ASTStatement.h>
#include <qasm/AST/ASTObjectTracker.h>

#include <map>

namespace QASM {

class ASTIfStatementBuilder : public ASTBase {
private:
  static ASTIfStatementBuilder CB;
  static std::map<unsigned, ASTStatementList*> IfMap;
  mutable unsigned ISC;
  mutable unsigned CISC;

protected:
  ASTIfStatementBuilder() : ISC(0U), CISC(0U) { }

public:
  using map_type = std::map<unsigned, ASTStatementList*>;
  using iterator = typename map_type::iterator;
  using const_iterator = typename map_type::const_iterator;

public:
  static ASTIfStatementBuilder& Instance() {
    return CB;
  }

  ASTStatementList* NewList() const {
    ASTStatementList* SL = new ASTStatementList(ISC);
    assert(SL && "Could not create an ASTStatementList!");

    if (!IfMap.insert(std::make_pair(ISC, SL)).second) {
      ASTObjectTracker::Instance().Unregister(SL);
      delete SL;
      return const_cast<ASTStatementList*>(IfMap[ISC]);
    }

    ISC += 1;
    CISC = ISC;
    return SL;
  }

  ASTStatementList* List() const {
    const_iterator I = IfMap.find(CISC);
    return I == IfMap.end() ? nullptr : (*I).second;
  }

  ASTStatementList* List(unsigned LI) const {
    const_iterator I = IfMap.find(LI);
    return I == IfMap.end() ? nullptr : (*I).second;
  }

  unsigned GetMapIndex() const {
    return ISC;
  }

  unsigned GetCurrentMapIndex() const {
    return CISC;
  }

  void CloseCurrentMapIndex() {
    if (CISC)
      CISC -= 1;
    if (ISC)
      ISC -= 1;
  }

  void Append(ASTStatementNode* SN) {
    assert(SN && "Invalid ASTStatementNode argument!");
    if (!SN->IsDirective())
      IfMap[ISC]->Append(SN);
  }

  virtual ASTType GetASTType() const override {
    return ASTTypeUndefined;
  }

  virtual void print() const override { }

  virtual void push(ASTBase* /* unused */) override { }
};

class ASTElseIfStatementBuilder : public ASTBase {
private:
  static ASTElseIfStatementBuilder CB;
  static std::map<unsigned, ASTStatementList*> ElseIfMap;
  mutable unsigned ISC;
  mutable unsigned CISC;

protected:
  ASTElseIfStatementBuilder() : ISC(0U), CISC(0U) { }

public:
  using map_type = std::map<unsigned, ASTStatementList*>;
  using iterator = typename map_type::iterator;
  using const_iterator = typename map_type::const_iterator;

public:
  static ASTElseIfStatementBuilder& Instance() {
    return CB;
  }

  ASTStatementList* NewList() const {
    ASTStatementList* SL = new ASTStatementList(ISC);
    assert(SL && "Could not create an ASTStatementList!");

    if (!ElseIfMap.insert(std::make_pair(ISC, SL)).second) {
      ASTObjectTracker::Instance().Unregister(SL);
      delete SL;
      return const_cast<ASTStatementList*>(ElseIfMap[ISC]);
    }

    ISC += 1;
    CISC = ISC;
    return SL;
  }

  ASTStatementList* List() const {
    const_iterator I = ElseIfMap.find(CISC);
    return I == ElseIfMap.end() ? nullptr : (*I).second;
  }

  ASTStatementList* List(unsigned LI) const {
    const_iterator I = ElseIfMap.find(LI);
    return I == ElseIfMap.end() ? nullptr : (*I).second;
  }

  unsigned GetMapIndex() const {
    return ISC;
  }

  unsigned GetCurrentMapIndex() const {
    return CISC;
  }

  void CloseCurrentMapIndex() {
    if (CISC)
      CISC -= 1;
    if (ISC)
      ISC -= 1;
  }

  void Append(ASTStatementNode* SN) {
    assert(SN && "Invalid ASTStatementNode argument!");
    if (!SN->IsDirective())
      ElseIfMap[ISC]->Append(SN);
  }

  virtual ASTType GetASTType() const override {
    return ASTTypeUndefined;
  }

  virtual void print() const override { }

  virtual void push(ASTBase* /* unused */) override { }
};

class ASTElseStatementBuilder : public ASTBase {
private:
  static ASTElseStatementBuilder CB;
  static std::map<unsigned, ASTStatementList*> ElseMap;
  mutable unsigned ISC;
  mutable unsigned CISC;

protected:
  ASTElseStatementBuilder() : ISC(0U), CISC(0U) { }

public:
  using map_type = std::map<unsigned, ASTStatementList*>;
  using iterator = typename map_type::iterator;
  using const_iterator = typename map_type::const_iterator;

public:
  static ASTElseStatementBuilder& Instance() {
    return CB;
  }

  ASTStatementList* NewList() const {
    ASTStatementList* SL = new ASTStatementList(ISC);
    assert(SL && "Could not create an ASTStatementList!");

    if (!ElseMap.insert(std::make_pair(ISC, SL)).second) {
      ASTObjectTracker::Instance().Unregister(SL);
      delete SL;
      return const_cast<ASTStatementList*>(ElseMap[ISC]);
    }

    ISC += 1;
    CISC = ISC;
    return SL;
  }

  ASTStatementList* List() const {
    const_iterator I = ElseMap.find(CISC);
    return I == ElseMap.end() ? nullptr : (*I).second;
  }

  ASTStatementList* List(unsigned LI) const {
    const_iterator I = ElseMap.find(LI);
    return I == ElseMap.end() ? nullptr : (*I).second;
  }

  unsigned GetMapIndex() const {
    return ISC;
  }

  unsigned GetCurrentMapIndex() const {
    return CISC;
  }

  void CloseCurrentMapIndex() {
    if (CISC)
      CISC -= 1;
    if (ISC)
      ISC -= 1;
  }

  void Append(ASTStatementNode* SN) {
    assert(SN && "Invalid ASTStatementNode argument!");
    if (!SN->IsDirective())
      ElseMap[ISC]->Append(SN);
  }

  virtual ASTType GetASTType() const override {
    return ASTTypeUndefined;
  }

  virtual void print() const override { }

  virtual void push(ASTBase* /* unused */) override { }
};

} // namespace QASM

#endif // __QASM_AST_IF_STATEMENT_BUILDER_H

