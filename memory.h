#pragma once
#include "definition.h"

PVOID get_system_module_base(const char* module_name);

PVOID get_system_module_export(const char* module_name, LPCSTR routine_name);
PVOID get_system_module_export(LPCWSTR module_name, LPCSTR routine_name);

bool write_memory(void* address, void* buffer, size_t size);
bool write_to_read_only(void* address, void* buffer, size_t size);
ULONG get_module_base_x64(PEPROCESS proc, UNICODE_STRING module_name);
bool read_kernel_memory(HANDLE pId, uintptr_t address, void* buffer, SIZE_T size);
bool write_kernel_memory(HANDLE pId, uintptr_t address, void* buffer, SIZE_T size);
PVOID get_system_routine_address(PCWSTR routine_name);


typedef struct _TAILS_MEMORY {
	void* bufferAddr;
	UINT_PTR address;
	ULONGLONG size;
	ULONG pID;
	BOOLEAN read;
	BOOLEAN write;
	BOOLEAN reqBase;
	BOOLEAN draw_box;
	int r, g, b, x, y, w, h, t;
	void* output;
	const char* module_name;
	ULONG64 base_address;

}TAILS_MEMORY;
