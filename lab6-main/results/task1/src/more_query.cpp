#include <CL/sycl.hpp>
#include <iostream>

// Esto nos permite eliminar cl::sycl:: de todas las invocaciones
using namespace cl::sycl;

int main() {
    try {
        cpu_selector selector_cpu;
        gpu_selector selector_gpu;
        default_selector selector_default;
        accelerator_selector selector_accelerator;

        // Crear colas para cada tipo de selector
        queue q_cpu(selector_cpu);
        queue q_gpu(selector_gpu);
        queue q_default(selector_default);
        queue q_accelerator(selector_accelerator);

        // Imprimir información sobre los dispositivos
        std::cout << "CPU Device: " << q_cpu.get_device().get_info<info::device::name>() << std::endl;
        std::cout << "GPU Device: " << q_gpu.get_device().get_info<info::device::name>() << std::endl;
        std::cout << "Default Device: " << q_default.get_device().get_info<info::device::name>() << std::endl;
        std::cout << "Accelerator Device: " << q_accelerator.get_device().get_info<info::device::name>() << std::endl;

    } catch (const sycl::exception& e) {
        std::cerr << "SYCL exception caught: " << e.what() << std::endl;
        return 1; // Retornar un código de error
    } catch (const std::exception& e) {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
        return 1; // Retornar un código de error
    }

    return 0;
}