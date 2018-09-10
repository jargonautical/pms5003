#ifndef _LIBRARIES_COMPACT_OPTIONAL_H_
#define _LIBRARIES_COMPACT_OPTIONAL_H_

// Class contains Arduino implementation of compact_optional template
//
// Selected value means something special: similar to `none` from boost::optional
//
// Created by https://github.com/jbanaszczyk

namespace jb {
	namespace logic {
		template <typename T, T NullValue>
		class compact_optional {
		private:
			T storage;
		public:
			compact_optional() : storage(NullValue) { }
			explicit compact_optional(T storage) : storage(storage) { }

			void unSet() {
				storage = NullValue;
			}

			T& operator=(const T& other) {
				storage = other;
				return storage;
			}

			bool hasValue() const {
				return storage != NullValue;
			}

			explicit operator bool() const {
				return hasValue();
			}

			T getValue() {
				return storage;
			}

			operator T() const {
				return storage;
			}

			const T& operator->() const {
				return storage;
			}
		};
	}
}

#endif
