function(convert_pascalcase_to_upper_snakecase input_pascalcase output_upper_snakecase)
    # replace PascalCase with Pascal_Case (insert `_` between lowercase and uppercase)
    string(REGEX REPLACE "([a-z])([A-Z])" "\\1_\\2" VAR_WITH_UNDERSCORE ${input_pascalcase})

    # convert Pascal_Case to PASCAL_CASE
    string(TOUPPER ${VAR_WITH_UNDERSCORE} VAR_UPPERCASE_WITH_UNDERSCORE)

    # return to `output_upper_snakecase` variable
    set(${output_upper_snakecase} ${VAR_UPPERCASE_WITH_UNDERSCORE} PARENT_SCOPE)
endfunction()
