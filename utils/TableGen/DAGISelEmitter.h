//===- DAGISelEmitter.h - Generate an instruction selector ------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This tablegen backend emits a DAG instruction selector.
//
//===----------------------------------------------------------------------===//

#ifndef DAGISEL_EMITTER_H
#define DAGISEL_EMITTER_H

#include "CodeGenDAGPatterns.h"
#include <set>

namespace llvm {

/// DAGISelEmitter - The top-level class which coordinates construction
/// and emission of the instruction selector.
///
class DAGISelEmitter : public TableGenBackend {
  RecordKeeper &Records;
  CodegenDAGPatterns *CGP; 
public:
  DAGISelEmitter(RecordKeeper &R) : Records(R) {}

  // run - Output the isel, returning true on failure.
  void run(std::ostream &OS);
  
  
private:
  void GenerateCodeForPattern(PatternToMatch &Pattern,
                  std::vector<std::pair<unsigned, std::string> > &GeneratedCode,
                              std::set<std::string> &GeneratedDecl,
                              std::vector<std::string> &TargetOpcodes,
                              std::vector<std::string> &TargetVTs);
  void EmitPatterns(std::vector<std::pair<PatternToMatch*, 
                  std::vector<std::pair<unsigned, std::string> > > > &Patterns, 
                    unsigned Indent, std::ostream &OS);
  void EmitInstructionSelector(std::ostream &OS);
};

} // End llvm namespace

#endif
