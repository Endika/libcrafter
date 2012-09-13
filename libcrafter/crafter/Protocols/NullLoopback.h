/*
Copyright (c) 2012, Esteban Pellegrino
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ESTEBAN PELLEGRINO BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef NULLLOOPBACK_H_
#define NULLLOOPBACK_H_

#include "../Layer.h"

namespace Crafter {

    class NullLoopback: public Layer {

        void DefineProtocol();

        Constructor GetConstructor() const {
            return NullLoopback::NullLoopbackConstFunc;
        };

        static Layer* NullLoopbackConstFunc() {
            return new NullLoopback;
        };

        void Craft();

        void ParseLayerData(ParseInfo* info);

        static const byte FieldFamily = 0;

    public:

        static const word PROTO = 0xfff5;

        NullLoopback();

        void SetFamily(const word& value) {
            SetFieldValue(FieldFamily,value);
        };

        word  GetFamily() const {
            return GetFieldValue<word>(FieldFamily);
        };

        ~NullLoopback() { /* Destructor */ };

    };

}

#endif /* NULLLOOPBACK_H_ */