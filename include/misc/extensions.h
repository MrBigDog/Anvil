//
// Copyright (c) 2018 Advanced Micro Devices, Inc. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
#ifndef MISC_EXTENSIONS_H
#define MISC_EXTENSIONS_H

#include "misc/debug.h"
#include "misc/types.h"

namespace Anvil
{
    namespace Internal
    {
        template<typename ValueType>
        struct DeviceExtensions
        {
            ValueType amd_draw_indirect_count;
            ValueType amd_gcn_shader;
            ValueType amd_gpu_shader_half_float;
            ValueType amd_gpu_shader_int16;
            ValueType amd_negative_viewport_height;
            ValueType amd_rasterization_order;
            ValueType amd_shader_ballot;
            ValueType amd_shader_core_properties;
            ValueType amd_shader_explicit_vertex_parameter;
            ValueType amd_shader_fragment_mask;
            ValueType amd_shader_image_load_store_lod;
            ValueType amd_shader_info;
            ValueType amd_shader_trinary_minmax;
            ValueType amd_texture_gather_bias_lod;
            ValueType ext_debug_marker;
            ValueType ext_descriptor_indexing;
            ValueType ext_shader_stencil_export;
            ValueType ext_shader_subgroup_ballot;
            ValueType ext_shader_subgroup_vote;
            ValueType khr_16bit_storage;
            ValueType khr_bind_memory2;
            ValueType khr_descriptor_update_template;
            ValueType khr_external_fence;
            ValueType khr_external_memory;
            ValueType khr_external_semaphore;
            ValueType khr_maintenance1;
            ValueType khr_maintenance3;
            ValueType khr_storage_buffer_storage_class;
            ValueType khr_swapchain;

            #if defined(_WIN32)
                ValueType khr_external_fence_win32;
                ValueType khr_external_memory_win32;
                ValueType khr_external_semaphore_win32;
            #else
                ValueType khr_external_fence_fd;
                ValueType khr_external_memory_fd;
                ValueType khr_external_semaphore_fd;
            #endif

            std::map<std::string, ValueType> values_by_extension_names;


            DeviceExtensions(const std::map<std::string, ValueType>& in_values_by_extension_names,
                             const ValueType&                        in_unspecified_extension_name_value)
            {
                typedef struct ExtensionData
                {
                    const char* name;
                    ValueType*  out_result_ptr;

                    ExtensionData(const char* in_name,
                                  ValueType*  in_out_result_ptr)
                        :name          (in_name),
                         out_result_ptr(in_out_result_ptr)
                    {
                        /* Stub */
                    }
                } ExtensionData;

                std::vector<ExtensionData> recognized_extensions =
                {
                    {ExtensionData(VK_AMD_DRAW_INDIRECT_COUNT_EXTENSION_NAME,              &amd_draw_indirect_count)},
                    {ExtensionData(VK_AMD_GCN_SHADER_EXTENSION_NAME,                       &amd_gcn_shader)},
                    {ExtensionData(VK_AMD_GPU_SHADER_HALF_FLOAT_EXTENSION_NAME,            &amd_gpu_shader_half_float)},
                    {ExtensionData(VK_AMD_GPU_SHADER_INT16_EXTENSION_NAME,                 &amd_gpu_shader_int16)},
                    {ExtensionData(VK_AMD_NEGATIVE_VIEWPORT_HEIGHT_EXTENSION_NAME,         &amd_negative_viewport_height)},
                    {ExtensionData(VK_AMD_RASTERIZATION_ORDER_EXTENSION_NAME,              &amd_rasterization_order)},
                    {ExtensionData(VK_AMD_SHADER_BALLOT_EXTENSION_NAME,                    &amd_shader_ballot)},
                    {ExtensionData("VK_AMD_shader_core_properties",                        &amd_shader_core_properties)},
                    {ExtensionData(VK_AMD_SHADER_EXPLICIT_VERTEX_PARAMETER_EXTENSION_NAME, &amd_shader_explicit_vertex_parameter)},
                    {ExtensionData(VK_AMD_SHADER_FRAGMENT_MASK_EXTENSION_NAME,             &amd_shader_fragment_mask)},
                    {ExtensionData(VK_AMD_SHADER_IMAGE_LOAD_STORE_LOD_EXTENSION_NAME,      &amd_shader_image_load_store_lod)},
                    {ExtensionData(VK_AMD_SHADER_INFO_EXTENSION_NAME,                      &amd_shader_info)},
                    {ExtensionData(VK_AMD_SHADER_TRINARY_MINMAX_EXTENSION_NAME,            &amd_shader_trinary_minmax)},
                    {ExtensionData(VK_AMD_TEXTURE_GATHER_BIAS_LOD_EXTENSION_NAME,          &amd_texture_gather_bias_lod)},
                    {ExtensionData(VK_EXT_DEBUG_MARKER_EXTENSION_NAME,                     &ext_debug_marker)},
                    {ExtensionData(VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME,              &ext_descriptor_indexing)},
                    {ExtensionData(VK_EXT_SHADER_STENCIL_EXPORT_EXTENSION_NAME,            &ext_shader_stencil_export)},
                    {ExtensionData(VK_EXT_SHADER_SUBGROUP_BALLOT_EXTENSION_NAME,           &ext_shader_subgroup_ballot)},
                    {ExtensionData(VK_EXT_SHADER_SUBGROUP_VOTE_EXTENSION_NAME,             &ext_shader_subgroup_vote)},
                    {ExtensionData(VK_KHR_16BIT_STORAGE_EXTENSION_NAME,                    &khr_16bit_storage)},
                    {ExtensionData(VK_KHR_DESCRIPTOR_UPDATE_TEMPLATE_EXTENSION_NAME,       &khr_descriptor_update_template)},
                    {ExtensionData(VK_KHR_EXTERNAL_FENCE_EXTENSION_NAME,                   &khr_external_fence)},
                    {ExtensionData(VK_KHR_EXTERNAL_MEMORY_EXTENSION_NAME,                  &khr_external_memory)},
                    {ExtensionData(VK_KHR_EXTERNAL_SEMAPHORE_EXTENSION_NAME,               &khr_external_semaphore)},
                    #if defined(_WIN32)
                        {ExtensionData(VK_KHR_EXTERNAL_FENCE_WIN32_EXTENSION_NAME,     &khr_external_fence_win32)},
                        {ExtensionData(VK_KHR_EXTERNAL_MEMORY_WIN32_EXTENSION_NAME,    &khr_external_memory_win32)},
                        {ExtensionData(VK_KHR_EXTERNAL_SEMAPHORE_WIN32_EXTENSION_NAME, &khr_external_semaphore_win32)},
                    #else
                        {ExtensionData(VK_KHR_EXTERNAL_FENCE_FD_EXTENSION_NAME,     &khr_external_fence_fd)},
                        {ExtensionData(VK_KHR_EXTERNAL_MEMORY_FD_EXTENSION_NAME,    &khr_external_memory_fd)},
                        {ExtensionData(VK_KHR_EXTERNAL_SEMAPHORE_FD_EXTENSION_NAME, &khr_external_semaphore_fd)},
                    #endif
                    {ExtensionData(VK_KHR_MAINTENANCE1_EXTENSION_NAME,                     &khr_maintenance1)},
                    {ExtensionData(VK_KHR_MAINTENANCE3_EXTENSION_NAME,                     &khr_maintenance3)},
                    {ExtensionData(VK_KHR_BIND_MEMORY_2_EXTENSION_NAME,                    &khr_bind_memory2)},
                    {ExtensionData(VK_KHR_STORAGE_BUFFER_STORAGE_CLASS_EXTENSION_NAME,     &khr_storage_buffer_storage_class)},
                    {ExtensionData(VK_KHR_SWAPCHAIN_EXTENSION_NAME,                        &khr_swapchain)},
                };

                values_by_extension_names = in_values_by_extension_names;

                for (const auto& current_extension_data : recognized_extensions)
                {
                    auto extension_iterator = in_values_by_extension_names.find(current_extension_data.name);

                    if (extension_iterator != in_values_by_extension_names.end() )
                    {
                        *current_extension_data.out_result_ptr = extension_iterator->second;
                    }
                    else
                    {
                        *current_extension_data.out_result_ptr                 = in_unspecified_extension_name_value;
                        values_by_extension_names[current_extension_data.name] = in_unspecified_extension_name_value;
                    }
                }
            }

        };

        template<typename ValueType>
        struct InstanceExtensions
        {
            ValueType khr_external_fence_capabilities;
            ValueType khr_external_memory_capabilities;
            ValueType khr_external_semaphore_capabilities;
            ValueType khr_get_physical_device_properties2;
            ValueType khr_surface;

            #ifdef _WIN32
                #if defined(ANVIL_INCLUDE_WIN3264_WINDOW_SYSTEM_SUPPORT)
                    ValueType khr_win32_surface;
                #endif
            #else
                #if defined(ANVIL_INCLUDE_XCB_WINDOW_SYSTEM_SUPPORT)
                    ValueType khr_xcb_surface;
                #endif
            #endif

            std::map<std::string, ValueType> values_by_extension_names;


            InstanceExtensions(const std::map<std::string, ValueType>& in_values_by_extension_names,
                               const ValueType&                        in_unspecified_extension_name_value)
            {
                typedef struct ExtensionData
                {
                    const char* name;
                    ValueType*  out_result_ptr;

                    ExtensionData(const char* in_name,
                                  ValueType*  in_out_result_ptr)
                        :name          (in_name),
                         out_result_ptr(in_out_result_ptr)
                    {
                        /* Stub */
                    }
                } ExtensionData;

                std::vector<ExtensionData> recognized_extensions =
                {
                    {ExtensionData(VK_KHR_EXTERNAL_FENCE_CAPABILITIES_EXTENSION_NAME,      &khr_external_fence_capabilities)},
                    {ExtensionData(VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME,     &khr_external_memory_capabilities)},
                    {ExtensionData(VK_KHR_EXTERNAL_SEMAPHORE_CAPABILITIES_EXTENSION_NAME,  &khr_external_semaphore_capabilities)},
                    {ExtensionData(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME, &khr_get_physical_device_properties2)},
                    {ExtensionData(VK_KHR_SURFACE_EXTENSION_NAME,                          &khr_surface)},

                    #ifdef _WIN32
                        #if defined(ANVIL_INCLUDE_WIN3264_WINDOW_SYSTEM_SUPPORT)
                            {ExtensionData(VK_KHR_WIN32_SURFACE_EXTENSION_NAME, &khr_win32_surface)},
                        #endif
                    #else
                        #if defined(ANVIL_INCLUDE_XCB_WINDOW_SYSTEM_SUPPORT)
                            {ExtensionData(VK_KHR_XCB_SURFACE_EXTENSION_NAME,   &khr_xcb_surface)},
                        #endif
                    #endif
                };

                values_by_extension_names = in_values_by_extension_names;

                for (const auto& current_extension_data : recognized_extensions)
                {
                    auto extension_iterator = in_values_by_extension_names.find(current_extension_data.name);

                    if (extension_iterator != in_values_by_extension_names.end() )
                    {
                        *current_extension_data.out_result_ptr = extension_iterator->second;
                    }
                    else
                    {
                        *current_extension_data.out_result_ptr                 = in_unspecified_extension_name_value;
                        values_by_extension_names[current_extension_data.name] = in_unspecified_extension_name_value;
                    }
                }
            }
        };
    };

    template<typename ValueType>
    class IExtensionInfoDevice
    {
    public:
        virtual ~IExtensionInfoDevice()
        {
            /* Stub */
        }

        virtual ValueType amd_draw_indirect_count             () const = 0;
        virtual ValueType amd_gcn_shader                      () const = 0;
        virtual ValueType amd_gpu_shader_half_float           () const = 0;
        virtual ValueType amd_gpu_shader_int16                () const = 0;
        virtual ValueType amd_negative_viewport_height        () const = 0;
        virtual ValueType amd_rasterization_order             () const = 0;
        virtual ValueType amd_shader_ballot                   () const = 0;
        virtual ValueType amd_shader_core_properties          () const = 0;
        virtual ValueType amd_shader_explicit_vertex_parameter() const = 0;
        virtual ValueType amd_shader_fragment_mask            () const = 0;
        virtual ValueType amd_shader_image_load_store_lod     () const = 0;
        virtual ValueType amd_shader_info                     () const = 0;
        virtual ValueType amd_shader_trinary_minmax           () const = 0;
        virtual ValueType amd_texture_gather_bias_lod         () const = 0;
        virtual ValueType ext_debug_marker                    () const = 0;
        virtual ValueType ext_descriptor_indexing             () const = 0;
        virtual ValueType ext_shader_stencil_export           () const = 0;
        virtual ValueType ext_shader_subgroup_ballot          () const = 0;
        virtual ValueType ext_shader_subgroup_vote            () const = 0;
        virtual ValueType khr_16bit_storage                   () const = 0;
        virtual ValueType khr_bind_memory2                    () const = 0;
        virtual ValueType khr_descriptor_update_template      () const = 0;
        virtual ValueType khr_external_fence                  () const = 0;
        virtual ValueType khr_external_memory                 () const = 0;
        virtual ValueType khr_external_semaphore              () const = 0;
        #if defined(_WIN32)
            virtual ValueType khr_external_fence_win32    () const = 0;
            virtual ValueType khr_external_memory_win32   () const = 0;
            virtual ValueType khr_external_semaphore_win32() const = 0;
        #else
            virtual ValueType khr_external_fence_fd    () const = 0;
            virtual ValueType khr_external_memory_fd   () const = 0;
            virtual ValueType khr_external_semaphore_fd() const = 0;
        #endif
        virtual ValueType khr_maintenance1                    () const = 0;
        virtual ValueType khr_maintenance3                    () const = 0;
        virtual ValueType khr_storage_buffer_storage_class    () const = 0;
        virtual ValueType khr_swapchain                       () const = 0;

        virtual ValueType by_name(const std::string& in_name) const = 0;
    };

    template<typename ValueType>
    class IExtensionInfoInstance
    {
    public:
        virtual ~IExtensionInfoInstance()
        {
            /* Stub */
        }

        virtual bool khr_external_fence_capabilities    () const = 0;
        virtual bool khr_external_memory_capabilities   () const = 0;
        virtual bool khr_external_semaphore_capabilities() const = 0;
        virtual bool khr_get_physical_device_properties2() const = 0;
        virtual bool khr_surface                        () const = 0;

        #ifdef _WIN32
            #if defined(ANVIL_INCLUDE_WIN3264_WINDOW_SYSTEM_SUPPORT)
                virtual bool khr_win32_surface() const = 0;
            #endif
        #else
            #if defined(ANVIL_INCLUDE_XCB_WINDOW_SYSTEM_SUPPORT)
                virtual bool khr_xcb_surface() const = 0;
            #endif
        #endif

        virtual bool by_name(const std::string& in_name) const = 0;
    };

    template<typename ValueType>
    class ExtensionInfo : private IExtensionInfoDevice<ValueType>,
                          private IExtensionInfoInstance<ValueType>
    {
    public:
        /* Public functions */
        static std::unique_ptr<ExtensionInfo<ValueType> > create_device_extension_info(const std::map<std::string, ValueType>& in_values_by_extension_names,
                                                                                       const ValueType&                        in_unspecified_extension_name_value)
        {
            std::unique_ptr<Anvil::ExtensionInfo<ValueType> > result_ptr;

            result_ptr.reset(
                new ExtensionInfo<ValueType>(true,               /* in_device_extensions */
                                             in_values_by_extension_names,
                                             in_unspecified_extension_name_value)
            );

            return result_ptr;
        }

        static std::unique_ptr<ExtensionInfo> create_instance_extension_info(const std::map<std::string, ValueType>& in_values_by_extension_names,
                                                                             const ValueType&                        in_unspecified_extension_name_value)
        {
            std::unique_ptr<Anvil::ExtensionInfo<ValueType> > result_ptr;

            result_ptr.reset(
                new ExtensionInfo<ValueType>(false,             /* in_device_extensions */
                                             in_values_by_extension_names,
                                             in_unspecified_extension_name_value)
            );

            return result_ptr;
        }

        const IExtensionInfoDevice<ValueType>* get_device_extension_info() const
        {
            anvil_assert(m_expose_device_extensions);

            return this;
        }

        const IExtensionInfoInstance<ValueType>* get_instance_extension_info() const
        {
            anvil_assert(!m_expose_device_extensions);

            return this;
        }

    private:
        /* Private functions */

        ExtensionInfo(const bool&                             in_device_extensions,
                      const std::map<std::string, ValueType>& in_values_by_extension_names,
                      const ValueType&                        in_unspecified_extension_name_value)
            :m_expose_device_extensions(in_device_extensions)
        {
            if (in_device_extensions)
            {
                m_device_extensions_ptr.reset(
                    new Internal::DeviceExtensions<ValueType>(in_values_by_extension_names,
                                                              in_unspecified_extension_name_value)
                );
            }
            else
            {
                m_instance_extensions_ptr.reset(
                    new Internal::InstanceExtensions<ValueType>(in_values_by_extension_names,
                                                                in_unspecified_extension_name_value)
                );
            }
            /* Stub */
        }

        ValueType by_name(const std::string& in_name) const final
        {
            if (m_expose_device_extensions)
            {
                return m_device_extensions_ptr->values_by_extension_names.at(in_name);
            }
            else
            {
                return m_instance_extensions_ptr->values_by_extension_names.at(in_name);
            }
        }

        /* IExtensionInfoDevice */

        ValueType amd_draw_indirect_count() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->amd_draw_indirect_count;
        }

        ValueType amd_gcn_shader() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->amd_gcn_shader;
        }

        ValueType amd_gpu_shader_half_float() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->amd_gpu_shader_half_float;
        }

        ValueType amd_gpu_shader_int16() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->amd_gpu_shader_int16;
        }

        ValueType amd_negative_viewport_height() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->amd_negative_viewport_height;
        }

        ValueType amd_rasterization_order() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->amd_rasterization_order;
        }

        ValueType amd_shader_ballot() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->amd_shader_ballot;
        }

        ValueType amd_shader_explicit_vertex_parameter() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->amd_shader_explicit_vertex_parameter;
        }

        ValueType amd_shader_fragment_mask() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->amd_shader_fragment_mask;
        }

        ValueType amd_shader_image_load_store_lod() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->amd_shader_image_load_store_lod;
        }

        ValueType amd_shader_core_properties() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->amd_shader_core_properties;
        }

        ValueType amd_shader_info() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->amd_shader_info;
        }

        ValueType amd_shader_trinary_minmax() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->amd_shader_trinary_minmax;
        }

        ValueType amd_texture_gather_bias_lod() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->amd_texture_gather_bias_lod;
        }

        ValueType ext_debug_marker() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->ext_debug_marker;
        }

        ValueType ext_descriptor_indexing() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->ext_descriptor_indexing;
        }

        ValueType ext_shader_stencil_export() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->ext_shader_stencil_export;
        }

        ValueType ext_shader_subgroup_ballot() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->ext_shader_subgroup_ballot;
        }

        ValueType ext_shader_subgroup_vote() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->ext_shader_subgroup_vote;
        }

        ValueType khr_16bit_storage() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->khr_16bit_storage;
        }

        ValueType khr_bind_memory2() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->khr_bind_memory2;
        }

        ValueType khr_descriptor_update_template() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->khr_descriptor_update_template;
        }

        ValueType khr_external_fence() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->khr_external_fence;
        }

        #if defined(_WIN32)
            ValueType khr_external_fence_win32() const final
            {
                anvil_assert(m_expose_device_extensions);

                return m_device_extensions_ptr->khr_external_fence_win32;
            }
        #else
            ValueType khr_external_fence_fd() const final
            {
                anvil_assert(m_expose_device_extensions);

                return m_device_extensions_ptr->khr_external_fence_fd;
            }
        #endif

        ValueType khr_external_memory() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->khr_external_memory;
        }

        #if defined(_WIN32)
            ValueType khr_external_memory_win32() const final
            {
                anvil_assert(m_expose_device_extensions);

                return m_device_extensions_ptr->khr_external_memory_win32;
            }
        #else
            ValueType khr_external_memory_fd() const final
            {
                anvil_assert(m_expose_device_extensions);

                return m_device_extensions_ptr->khr_external_memory_fd;
            }
        #endif

        ValueType khr_external_semaphore() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->khr_external_semaphore;
        }

        #if defined(_WIN32)
            ValueType khr_external_semaphore_win32() const final
            {
                anvil_assert(m_expose_device_extensions);

                return m_device_extensions_ptr->khr_external_semaphore_win32;
            }
        #else
            ValueType khr_external_semaphore_fd() const final
            {
                anvil_assert(m_expose_device_extensions);

                return m_device_extensions_ptr->khr_external_semaphore_fd;
            }
        #endif

        ValueType khr_maintenance1() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->khr_maintenance1;
        }

        ValueType khr_maintenance3() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->khr_maintenance3;
        }

        ValueType khr_storage_buffer_storage_class() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->khr_storage_buffer_storage_class;
        }

        ValueType khr_swapchain() const final
        {
            anvil_assert(m_expose_device_extensions);

            return m_device_extensions_ptr->khr_swapchain;
        }

        /* IExtensionInfoInstance */

        ValueType khr_external_fence_capabilities() const final
        {
            anvil_assert(!m_expose_device_extensions);

            return m_instance_extensions_ptr->khr_external_fence_capabilities;
        }

        ValueType khr_external_memory_capabilities() const final
        {
            anvil_assert(!m_expose_device_extensions);

            return m_instance_extensions_ptr->khr_external_memory_capabilities;
        }

        ValueType khr_external_semaphore_capabilities() const final
        {
            anvil_assert(!m_expose_device_extensions);

            return m_instance_extensions_ptr->khr_external_semaphore_capabilities;
        }

        ValueType khr_get_physical_device_properties2() const final
        {
            anvil_assert(!m_expose_device_extensions);

            return m_instance_extensions_ptr->khr_get_physical_device_properties2;
        }

        ValueType khr_surface() const final
        {
            anvil_assert(!m_expose_device_extensions);

            return m_instance_extensions_ptr->khr_surface;
        }


        #ifdef _WIN32
            #if defined(ANVIL_INCLUDE_WIN3264_WINDOW_SYSTEM_SUPPORT)
                ValueType khr_win32_surface() const final
                {
                    anvil_assert(!m_expose_device_extensions);

                    return m_instance_extensions_ptr->khr_win32_surface;
                }
            #endif
        #else
            #if defined(ANVIL_INCLUDE_XCB_WINDOW_SYSTEM_SUPPORT)
                ValueType khr_xcb_surface() const final
                {
                    anvil_assert(!m_expose_device_extensions);

                    return m_instance_extensions_ptr->khr_xcb_surface;
                }
            #endif
        #endif

        /* Private variables */

        std::unique_ptr<Internal::DeviceExtensions<ValueType> >   m_device_extensions_ptr;
        bool                                                      m_expose_device_extensions;
        std::unique_ptr<Internal::InstanceExtensions<ValueType> > m_instance_extensions_ptr;
    };

    /** A struct which tells which extensions must (or should, if supported by the physical device) be enabled
     *  at device creation time.
     */
    typedef struct DeviceExtensionConfiguration
    {
        DeviceExtensionConfiguration()
        {
            /* NOTE: By default, Anvil enables nearly all extensions it has support implemented for, which are reported
             *       as available.
             */
            {
                Internal::DeviceExtensions<bool> reference(std::map<std::string, bool>(),
                                                           false); /* in_unspecified_extension_name_value */

                for (const auto& current_extension_data : reference.values_by_extension_names)
                {
                    extension_status[current_extension_data.first] = EXTENSION_AVAILABILITY_ENABLE_IF_AVAILABLE;
                }
            }

            /*
             * A few exceptions exist.
             *
             * 1. VK_AMD_negative_viewport_height interacts with KHR_maintenance1, apps will have to enable it manually. */
            extension_status[VK_AMD_NEGATIVE_VIEWPORT_HEIGHT_EXTENSION_NAME] = EXTENSION_AVAILABILITY_IGNORE;

            /* 2. VK_EXT_debug_marker is only useful for debugging. */
            #if !defined(_DEBUG)
            {
                extension_status[VK_EXT_DEBUG_MARKER_EXTENSION_NAME] = EXTENSION_AVAILABILITY_IGNORE;
            }
            #endif

            /* 3. Disable VK_AMD_shader_info by default. */
            extension_status[VK_AMD_SHADER_INFO_EXTENSION_NAME] = EXTENSION_AVAILABILITY_IGNORE;
        }
 
        std::map<std::string, ExtensionAvailability> extension_status;

        bool operator==(const DeviceExtensionConfiguration& in_config) const
        {
            return (extension_status == in_config.extension_status);
        }
    } DeviceExtensionConfiguration;
};

#endif /* MISC_EXTENSIONS_H */