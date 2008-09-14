// Copyright 2007, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include <ctime>
#include <iomanip>
#include <cstring>

#include <algorithm>
#include "logging.h"

namespace logging {

const char* const log_severity_names[LOG_NUM_SEVERITIES] = {
  "INFO", "WARNING", "ERROR", "FATAL" };

int min_log_level = 0;
LogLockingState lock_log_file = LOCK_LOG_FILE;
LoggingDestination logging_destination = LOG_ONLY_TO_FILE;

const int kMaxFilteredLogLevel = LOG_WARNING;
char* log_filter_prefix = NULL;


// what should be prepended to each message?
bool log_process_id = false;
bool log_thread_id = false;
bool log_timestamp = true;
bool log_tickcount = false;

// An assert handler override specified by the client to be called instead of 
// the debug message dialog.
LogAssertHandlerFunction log_assert_handler = NULL;

// The critical section is used if log file locking is false. It helps us
// avoid problems with multiple threads writing to the log file at the same
// time.
bool initialized_critical_section = false;

// When we don't use a critical section, we are using a global mutex. We
// need to do this because LockFileEx is not thread safe

// Called by logging functions to ensure that debug_file is initialized
// and can be used for writing. Returns false if the file could not be
// initialized. debug_file will be NULL in this case.
bool InitializeLogFileHandle() {

  return true;
}

void InitLogMutex() {

}

void InitLogging(const char* new_log_file, LoggingDestination logging_dest,
                 LogLockingState lock_log, OldFileDeletionState delete_old) {

}

void SetMinLogLevel(int level) {
  min_log_level = level;
}

void SetLogFilterPrefix(char* filter)  {

}

void SetLogItems(bool enable_process_id, bool enable_thread_id,
                 bool enable_timestamp, bool enable_tickcount) {

}

void SetLogAssertHandler(LogAssertHandlerFunction handler) {

}

// Displays a message box to the user with the error message in it. For
// Windows programs, it's possible that the message loop is messed up on
// a fatal error, and creating a MessageBox will cause that message loop
// to be run. Instead, we try to spawn another process that displays its
// command line. We look for "Debug Message.exe" in the same directory as
// the application. If it exists, we use it, otherwise, we use a regular
// message box.
void DisplayDebugMessage(const std::string& str) {

}

LogMessage::LogMessage(const char* file, int line, LogSeverity severity,
		       int ctr)
    : severity_(severity) {

}

LogMessage::LogMessage(const char* file, int line, const CheckOpString& result)
    : severity_(LOG_FATAL) {

}

LogMessage::LogMessage(const char* file, int line)
     : severity_(LOG_INFO) {

}

LogMessage::LogMessage(const char* file, int line, LogSeverity severity)
    : severity_(severity) {

}

// writes the common header info to the stream
void LogMessage::Init(const char* file, int line) {

}

LogMessage::~LogMessage() {

}

void CloseLogFile() {

}

} // namespace logging

std::ostream& operator<<(std::ostream& out, const char* wstr) {

}
