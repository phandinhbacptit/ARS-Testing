/*!
 * \file
 * \author Miroslav Kubik <mkubik2@retia.cz>
 * \brief Header file with R_UNUSED macro.
 */
#ifndef RUTIL_UNUSED_H
#define RUTIL_UNUSED_H

/*!
 * This macro may be used to suppress "unused parameter" warnings,
 * which would otherwise arise frequently in a polymorphic software,
 * where a parameter may be ignored in the subclass or may be dummy
 * in the superclass.
 *
 * The macro is used in the following way:
 * void foo(int usedParam, int unusedParam)
 * {
 *   R_UNUSED(unusedParam);
 *   bar(usedParam);
 * }
 */
#define R_UNUSED(expr) do { (void)(expr); } while (0)

#endif /* RUTIL_UNUSED_H */
