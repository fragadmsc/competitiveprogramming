useful functions for competitive programming (here i didn't put the most obvious ones, as push_back() or max())
       // are all of the elements positive?
       all_of(first, first+n, ispositive()); 

      // is there at least one positive element?
      any_of(first, first+n, ispositive());

      // are none of the elements positive?
      none_of(first, first+n, ispositive()); 
      (of course, this works also with isnegative)
