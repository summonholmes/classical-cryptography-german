ModMatShape <-
  function(key_ident, i, alpha_len, matrix_len)
  {
    for (j in 1:matrix_len)
    {
      if (j != i)
      {
        key_ident[j, ] <-
          (key_ident[j, ] - (key_ident[j, i]) * key_ident[i, ]) %% alpha_len
      }
    }
    return (key_ident)
  }