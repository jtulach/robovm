/*
 * Copyright (C) 2010 The Android Open Source Project
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SCOPED_LOCAL_FRAME_H_included
#define SCOPED_LOCAL_FRAME_H_included

#include "JNIHelp.h"

class ScopedLocalFrame {
public:
    ScopedLocalFrame(JNIEnv* env) : mEnv(env) {
        mEnv->PushLocalFrame(128);
    }

    ~ScopedLocalFrame() {
        mEnv->PopLocalFrame(NULL);
    }

private:
    JNIEnv* mEnv;

    // Disallow copy and assignment.
    ScopedLocalFrame(const ScopedLocalFrame&);
    void operator=(const ScopedLocalFrame&);
};

#endif  // SCOPED_LOCAL_FRAME_H_included
