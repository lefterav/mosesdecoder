#pragma once
/*
 *  TargetPhrase.h
 *  CreateOnDisk
 *
 *  Created by Hieu Hoang on 31/12/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include <fstream>
#include <string>
#include <vector>
#include "Word.h"
#include "Phrase.h"

namespace Moses
{
	class PhraseDictionary;
	class TargetPhrase;
	class LMList;
	class Phrase;
}

namespace OnDiskPt
{

typedef std::pair<Moses::UINT64, Moses::UINT64>  AlignPair;
typedef std::vector<AlignPair> AlignType;

class TargetPhrase: public Phrase
{
	friend std::ostream& operator<<(std::ostream&, const TargetPhrase&);
protected:
	AlignType m_align;

	std::vector<float>	m_scores;
	Moses::UINT64 m_filePos;
	
	size_t WriteAlignToMemory(char *mem) const;
	size_t WriteScoresToMemory(char *mem) const;

	Moses::UINT64 ReadAlignFromFile(std::fstream &fileTPColl);
	Moses::UINT64 ReadScoresFromFile(std::fstream &fileTPColl);

public:
	TargetPhrase(size_t numScores);
	TargetPhrase(const 	TargetPhrase &copy);
	virtual ~TargetPhrase();

	void SetLHS(Word *lhs);

	void Create1AlignFromString(const std::string &align1Str);
	void SetScore(float score, size_t ind);

	const AlignType &GetAlign() const
	{ return m_align; }
	void SortAlign();

	char *WriteToMemory(OnDiskWrapper &onDiskWrapper, size_t &memUsed) const;
	char *WriteOtherInfoToMemory(OnDiskWrapper &onDiskWrapper, size_t &memUsed) const;
	void Save(OnDiskWrapper &onDiskWrapper);

	Moses::UINT64 GetFilePos() const
	{ return m_filePos; }
	float GetScore(size_t ind) const
	{ return m_scores[ind]; }

	Moses::TargetPhrase *ConvertToMoses(const std::vector<Moses::FactorType> &inputFactors
																			, const std::vector<Moses::FactorType> &outputFactors
																			, const Vocab &vocab
																			, const Moses::PhraseDictionary &phraseDict
																			, const std::vector<float> &weightT
																			, float weightWP
																			, const Moses::LMList &lmList
																			, const Moses::Phrase &sourcePhrase) const;
	Moses::UINT64 ReadOtherInfoFromFile(Moses::UINT64 filePos, std::fstream &fileTPColl);
	Moses::UINT64 ReadFromFile(std::fstream &fileTP, size_t numFactors);
	
};

}