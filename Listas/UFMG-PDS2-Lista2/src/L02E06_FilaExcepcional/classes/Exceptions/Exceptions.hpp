#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>

namespace Exceptions {
    class CustomException {
        public:
            std::string name;

            CustomException() : name("CustomException") {}

        protected:
            CustomException(const std::string name) : name(name) {}

        public:
            virtual ~CustomException() {}
        
            std::string getName() const {
                return name;
            }
    };

    class InvalidSizeException : public CustomException {
        public:
            InvalidSizeException() : CustomException("InvalidSizeException") {}
            virtual ~InvalidSizeException() {}
    };

    class QueueFullException : public CustomException {
        public:
            QueueFullException() : CustomException("QueueFullException") {}
            virtual ~QueueFullException() {}
    };

    class QueueEmptyException : public CustomException {
        public:
            QueueEmptyException() : CustomException("QueueEmptyException") {}
            virtual ~QueueEmptyException() {}
    };

    class ItemNotFoundException : public CustomException {
        public:
            ItemNotFoundException() : CustomException("ItemNotFoundException") {}
            virtual ~ItemNotFoundException() {}
    };
}

#endif
