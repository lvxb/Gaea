/*
 *  Copyright Beijing 58 Information Technology Co.,Ltd.
 *
 *  Licensed to the Apache Software Foundation (ASF) under one
 *  or more contributor license agreements.  See the NOTICE file
 *  distributed with this work for additional information
 *  regarding copyright ownership.  The ASF licenses this file
 *  to you under the Apache License, Version 2.0 (the
 *  "License"); you may not use this file except in compliance
 *  with the License.  You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing,
 *  software distributed under the License is distributed on an
 *  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 *  KIND, either express or implied.  See the License for the
 *  specific language governing permissions and limitations
 *  under the License.
 */
#ifndef __serializer
#define __serializer
#define SERIALIZE_CHAR "char"
#define SERIALIZE_SHORT_INT "short"
#define SERIALIZE_INT "int"
#define SERIALIZE_BOOL "bool"
#define SERIALIZE_BOOL1 "BOOL"
#define SERIALIZE_BOOL2 "BOOLEAN"
#define SERIALIZE_FLOAT "float"
#define SERIALIZE_DOUBLE "double"
#define SERIALIZE_TIME "time_t"
#define SERIALIZE_LONG "long"
#define SERIALIZE_LONG_LONG "long long"
#define SERIALIZE_STRUCT "struct"
#define SERIALIZE_ARRAY "array"
#define SERIALIZE_LIST "serialize_list"
#define SERIALIZE_MAP "cache_ptr"
#define SERIALIZE_STRING "string"
#define SERIALIZE_NULL "null"
#define SERIALIZE_VOID "void"
#define SERIALIZE_ENUM "enum_field"

#define SERIALIZE_CHAR_N 5
#define SERIALIZE_BOOL_N 3
#define SERIALIZE_SHORT_INT_N 7
#define SERIALIZE_INT_N 9
#define SERIALIZE_FLOAT_N 13
#define SERIALIZE_DOUBLE_N 14
#define SERIALIZE_TIME_N 16
#define SERIALIZE_LONG_LONG_N 11
#define SERIALIZE_STRUCT_N 18
#define SERIALIZE_ARRAY_N 23
#define SERIALIZE_LIST_N 19
#define SERIALIZE_MAP_N 24
#define SERIALIZE_STRING_N 18
#define SERIALIZE_NULL_N 0
#define SERIALIZE_VOID_N 2
#define SERIALIZE_ENUM_N 25
#define enum_field char*

typedef struct {
	int byteLength;
	int objectLength;
	int typeId;
	char isPointe; //0：实体；1：指针
	void *data;
} array;

typedef struct {
	int typeId;
	char isPointe; //0：实体；1：指针
	char *fieldName;
	int offset;
} structFieldInfo;

typedef struct {
	array *outArray;
	int hashcode;
	array *refObjArray;
} serializerInfo;

typedef struct {
	int typeId;
	void *data;
} hashmapEntry;

typedef void (*serializer)(int, serializerInfo *, const void *);
serializer getSerializer(int typeId, const void *obj);
#ifdef __cplusplus
extern "C" {
#endif
char* Serialize(char *type, const void *obj, const int *retDataLen);
#ifdef __cplusplus
}
#endif
#endif
