
//Warum const&?
//const& zeigt das es nur eine refferenz ist  und die daten nicht verendert werden


template<typename T>
T mult(T const& v1, T const& v2) {
    return v1 * v2;
    }