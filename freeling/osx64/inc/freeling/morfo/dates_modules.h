//////////////////////////////////////////////////////////////////
//
//    FreeLing - Open Source Language Analyzers
//
//    Copyright (C) 2004   TALP Research Center
//                         Universitat Politecnica de Catalunya
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU General Public
//    License as published by the Free Software Foundation; either
//    version 3 of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    General Public License for more details.
//
//    You should have received a copy of the GNU General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//    contact: Lluis Padro (padro@lsi.upc.es)
//             TALP Research Center
//             despatx C6.212 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
////////////////////////////////////////////////////////////////

#ifndef _DATES_MOD
#define _DATES_MOD

#include <map>

#include "freeling/regexp.h"
#include "freeling/morfo/language.h"
#include "freeling/morfo/automat.h"

namespace freeling {

  // Date/time regular expressions definitions

  const std::wstring RE_ROMAN=L"^([IVXLCDM]+)$";

  // Default:
  const std::wstring RE_DATE_DF=L"^(?:(?:((?:[0-3])?(?:\\d))/)(?:((?:(?:[0-1])?(?:\\d)))/)(\\d{1,4}))$";
  const std::wstring RE_TIME1_DF=L"^(?:((?:(?:[0-1])?(?:\\d))|(?:2(?:[0-4])))(?:h|:)(?:((?:[0-5])?(?:\\d))(?:min|m)?)?)$";
  const std::wstring RE_TIME2_DF=L"^(?:((?:[0-5])?(?:\\d))(?:min\\.?|m\\.?))$";

  // Spanish:
  const std::wstring RE_DATE_ES=L"^(?:(?:((?:[0-3])?(?:\\d))/)(?:((?:(?:[0-1])?(?:\\d))|enero|febrero|marzo|abril|mayo|junio|julio|agosto|septiembre|octubre|noviembre|diciembre|ene|feb|mar|abr|may|jun|jul|ago|sep|oct|nov|dic)/)(\\d{1,4}))$";
  const std::wstring RE_TIME1_ES=L"^(?:((?:(?:[0-1])?(?:\\d))|(?:2(?:[0-4])))(?:h|:)(?:((?:[0-5])?(?:\\d))(?:minutos|min|m)?)?)$";
  const std::wstring RE_TIME2_ES=L"^(?:((?:[0-5])?(?:\\d))(?:minutos|min\\.?|m\\.?))$";

  // Catalan:
  const std::wstring RE_DATE_CA=L"^(?:(?:((?:[0-3])?(?:\\d))/)(?:((?:(?:[0-1])?(?:\\d))|gener|febrer|març|abril|maig|juny|juliol|agost|setembre|octubre|novembre|desembre|gen|feb|mar|abr|mai|jun|jul|ago|set|oct|nov|des)/)(\\d{1,4}))$";
  const std::wstring RE_TIME1_CA=L"^(?:((?:(?:[0-1])?(?:\\d))|(?:2(?:[0-4])))(?:h|:)(?:((?:[0-5])?(?:\\d))(?:minuts|min|m)?)?)$";
  const std::wstring RE_TIME2_CA=L"^(?:((?:[0-5])?(?:\\d))(?:minuts|min\\.?|m\\.?))$";

  // English:
  const std::wstring RE_DATE_EN=L"^(?:(?:((?:[0-3])?(?:\\d))/)(?:((?:(?:[0-1])?(?:\\d))|january|february|march|april|may|june|july|august|september|october|november|december|jan|feb|mar|apr|may|jun|jul|aug|sep|oct|nov|dec)/)(\\d{1,4}))$";
  const std::wstring RE_TIME1_EN=L"^(?:((?:(?:[0-1])?(?:\\d))|(?:2(?:[0-4])))(?:h|:)(?:((?:[0-5])?(?:\\d))(?:minutes|min|m)?)?)$";
  const std::wstring RE_TIME2_EN=L"^(?:((?:[0-5])?(?:\\d))(?:minutes|min\\.?|m\\.?))$";

  // Galician:
  const std::wstring RE_DATE_GL=L"^(?:(?:((?:[0-3])?(?:\\d))/)(?:((?:(?:[0-1])?(?:\\d))|xaneiro|febreiro|marzo|abril|maio|xuño|xullo|agosto|setembro|outubro|novembro|decembro|xan|feb|mar|abr|mai|xuñ|xul|ago|set|out|nov|dec)/)(\\d{1,4}))$";
  const std::wstring RE_TIME1_GL=L"^(?:((?:(?:[0-1])?(?:\\d))|(?:2(?:[0-4])))(?:h|:)(?:((?:[0-5])?(?:\\d))(?:minutos|min|m)?)?)$";
  const std::wstring RE_TIME2_GL=L"^(?:((?:[0-5])?(?:\\d))(?:minutos|min\\.?|m\\.?))$";

  // Portuguese:
  const std::wstring RE_DATE_PT=L"^(?:(?:((?:[0-3])?(?:\\d))/)(?:((?:(?:[0-1])?(?:\\d))|janeiro|fevereiro|março|abril|maio|junho|julho|agosto|setembro|outubro|novembro|dezembro|jan|fev|mar|abr|mai|jun|jul|ago|set|out|nov|dez)/)(\\d{1,4}))$";
  const std::wstring RE_TIME1_PT=L"^(?:((?:(?:[0-1])?(?:\\d))|(?:2(?:[0-4])))(?:h|:)(?:((?:[0-5])?(?:\\d))(?:minutos|min|m)?)?)$";
  const std::wstring RE_TIME2_PT=L"^(?:((?:[0-5])?(?:\\d))(?:minutos|min\\.?|m\\.?))$";

  // Russian:
  const std::wstring RE_DATE_RU=L"^([0]?[1-9]|[1|2][0-9]|[3][0|1])[./]([0]?[1-9]|[1][0-2])[./]([0-9]{4}|[0-9]{2})$";
  const std::wstring RE_TIME_RU=L"^(?:((?:(?:[0-1])?(?:\\d))|(?:2(?:[0-4])))(?:ч\\.?|:)(?:((?:[0-5])?(?:\\d))(?:минуты?|мин\\.?)?)?)$";
  const std::wstring RE_MINUTES_RU=L"^(?:((?:[0-5])?(?:\\d))(?:минуты?|мин\\.?))$";

  // Value of unspecified fields in normalized date
  const std::wstring UNKNOWN_SYMB = L"??";

  ////////////////////////////////////////////////////////////////
  /// Class to store status information
  ////////////////////////////////////////////////////////////////

  class dates_status : public automat_status {
  public:
    /// interpretation of the date-time expression
    std::wstring century,year,month,day,weekday,hour,minute,meridian;
    /// auxiliary for interpretation building
    int temp;
    int sign;  // for Catalan "un quart menys(-1)/i(1) cinc de sis" or 
    // for English: a quarter to(-1)/past(1) five.

    int daytemp; // for special state Gbb in English
    bool inGbb; 

    std::vector<std::wstring> rem;  // remember results of last matched RegEx
  };

  ////////////////////////////////////////////////////////////////
  ///  The abstract class dates_module generalizes temporal
  /// expression recognizer for different languages.
  ////////////////////////////////////////////////////////////////

  class dates_module: public automat<dates_status> {

  protected:
    /// translate month names to numbers
    std::map<std::wstring,int> nMes;
    /// translate weekday names to unified codes
    std::map<std::wstring,std::wstring> nDia;
    /// translate particular wstrings to token codes
    std::map<std::wstring,int> tok;

    // required regular expressions objects
    freeling::regexp RE_Date;
    freeling::regexp RE_Time1;
    freeling::regexp RE_Time2;
    freeling::regexp RE_Roman;

    // to unify notation (01 -> 1), maybe adding an offset
    std::wstring normalize(const std::wstring &in, int offs=0) const;

  private:
    virtual void ResetActions(dates_status *) const;

  public:
    /// Constructor
    dates_module(const std::wstring &, const std::wstring &, const std::wstring &, const std::wstring &); 
    virtual ~dates_module() {}
  };


  ////////////////////////////////////////////////////////////////
  ///   The derived class dates_default implements a default date/time
  ///   recognizer (only simple patterns are recognized).
  ////////////////////////////////////////////////////////////////

  class dates_default : public dates_module {

  private:
    int ComputeToken(int, sentence::iterator &, sentence &) const;
    void StateActions(int, int, int, sentence::const_iterator, dates_status *) const;
    void SetMultiwordAnalysis(sentence::iterator, int, const dates_status *) const;

  public:
    /// Constructor
    dates_default();
  };

  ////////////////////////////////////////////////////////////////
  ///   The derived class dates_es implements a Spanish date/time
  ///   recognizer.
  ////////////////////////////////////////////////////////////////

  class dates_es : public dates_module {

  private:
    int ComputeToken(int, sentence::iterator &, sentence &) const;
    void StateActions(int, int, int, sentence::const_iterator, dates_status*) const;
    void SetMultiwordAnalysis(sentence::iterator, int, const dates_status*) const;

  public:
    /// Constructor
    dates_es();
  };


  ////////////////////////////////////////////////////////////////
  ///   The derived class dates_ca implements a Catalan date/time
  ///   recognizer.
  ////////////////////////////////////////////////////////////////

  class dates_ca : public dates_module {

  private:
    int ComputeToken(int, sentence::iterator &, sentence &) const;
    void StateActions(int, int, int, sentence::const_iterator, dates_status*) const;
    void SetMultiwordAnalysis(sentence::iterator, int, const dates_status*) const;

  public:
    /// Constructor
    dates_ca();
  };

  ////////////////////////////////////////////////////////////////
  ///   The derived class dates_gl implements a Galician date/time
  ///   recognizer.
  ////////////////////////////////////////////////////////////////

  class dates_gl : public dates_module {

  private:
    int ComputeToken(int, sentence::iterator &, sentence &) const;
    void StateActions(int, int, int, sentence::const_iterator, dates_status*) const;
    void SetMultiwordAnalysis(sentence::iterator, int, const dates_status*) const;

  public:
    /// Constructor
    dates_gl();
  };

  ////////////////////////////////////////////////////////////////
  ///   The derived class dates_pt implements a Portuguese date/time
  ///   recognizer.
  ////////////////////////////////////////////////////////////////

  class dates_pt : public dates_module {

  private:
    int ComputeToken(int, sentence::iterator &, sentence &) const;
    void StateActions(int, int, int, sentence::const_iterator, dates_status*) const;
    void SetMultiwordAnalysis(sentence::iterator, int, const dates_status*) const;

  public:
    /// Constructor
    dates_pt();
  };


  ////////////////////////////////////////////////////////////////
  ///   The derived class dates_en implements an English date/time
  ///   recognizer.
  ////////////////////////////////////////////////////////////////

  class dates_en : public dates_module {

  private:
    int ComputeToken(int, sentence::iterator &, sentence &) const;
    void StateActions(int, int, int, sentence::const_iterator, dates_status*) const;
    void SetMultiwordAnalysis(sentence::iterator, int, const dates_status*) const;

    /// translate day numbers (first, second...) to a number (1, 2...)
    std::map<std::wstring,int> numDay;

  public:
    /// Constructor
    dates_en();
  };

  ////////////////////////////////////////////////////////////////
  ///   The derived class dates_ru implements Russian date/time
  ///   recognizer.
  ////////////////////////////////////////////////////////////////

  class dates_ru : public dates_module {

  private:
    int ComputeToken(int, sentence::iterator &, sentence &) const;
    void StateActions(int, int, int, sentence::const_iterator, dates_status*) const;
    void SetMultiwordAnalysis(sentence::iterator, int, const dates_status*) const;

    int GetPrevStateValue(dates_status *) const;
    void SetPrevStateValue(int, dates_status *) const;

  public:
    /// Constructor
    dates_ru();
  };

} // namespace

#endif

