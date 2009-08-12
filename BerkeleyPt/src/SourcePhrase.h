#pragma once
/*
 *  SourcePhrase.h
 *  BerkeleyPt
 *
 *  Created by Hieu Hoang on 11/08/2009.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include <vector>
#include <db_cxx.h>
#include "Phrase.h"
#include "TargetPhrase.h"
#include "Word.h"

namespace MosesBerkeleyPt
{
	
class SourcePhrase : public Phrase
{
protected:
	std::vector<Word> m_targetNonTerms;

public:
	SourcePhrase();
	SourcePhrase(const 	SourcePhrase &copy);
	~SourcePhrase();
	
	size_t GetNumNonTerminals() const;
	
	void SaveTargetNonTerminals(const TargetPhrase &targetPhrase);
	long Save(Db &db, long &nextSourceId) const;
	long SaveWord(long currSourceNodeId, const Word &word, Db &db, long &nextSourceId) const;

	//! transitive comparison
	bool operator<(const SourcePhrase &compare) const;
};

}
