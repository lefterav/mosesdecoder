// $Id$

/***********************************************************************
Moses - factored phrase-based language decoder
Copyright (C) 2006 University of Edinburgh

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
***********************************************************************/

#ifndef _TRANSLATION_DECODE_STEP_H_
#define _TRANSLATION_DECODE_STEP_H_

#include "DecodeStep.h"

class PhraseDictionaryBase;
class TargetPhrase;

class TranslationDecodeStep : public DecodeStep
{
public:
	TranslationDecodeStep(PhraseDictionaryBase* dict, const DecodeStep* prev);

	// still sucks
	const int GetType() const { return 0; };

  /** returns phrase table (dictionary) for translation step */
  const PhraseDictionaryBase &GetPhraseDictionary() const;

  virtual void Process(const TranslationOption &inputPartialTranslOpt
                              , const DecodeStep &decodeStep
                              , PartialTranslOptColl &outputPartialTranslOptColl
                              , FactorCollection &factorCollection
                              , TranslationOptionCollection *toc) const;
private:
	TranslationOption *MergeTranslation(const TranslationOption& oldTO, const TargetPhrase &targetPhrase) const;
};

#endif