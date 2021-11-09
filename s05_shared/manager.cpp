#include <iostream>
#include <memory>

int main() {
        //std::shared_ptr<int> p(new int(42));
    {
        auto p = make_shared<int>(42);
        {
            auto q = p;
            {
                auto w = q;
                std::cout << p.use_count() << std::endl; //3
            }
        }
    }

}