<?php

/**
 * Class StructureHelp
 */
trait StructureHelp {
  /*** SETTERS AND GETTERS ***/
  /**
   * Returns a Ki from the object structure.
   *
   * @param string $name
   *   The Ki's name.
   *
   * @return KiBase
   */
  public function kiGet($name) {
    $struct = $this->getStructure();

    if (isset($struct[$name])) {
      return $struct;
    }
  }
  /*** SETTERS AND GETTERS END ***/

  /*** HASSERS ***/
  /*** HASSERS END ***/

  /*** ISSERS ***/
  /*** ISSERS END ***/

  /*** EVAL METHODS ***/
  /**
   * Guesses the structure generation method.
   *
   * @return string
   */
  public function structGenMethodGuess() {
    return $this->__isset('model') ? 'genFromModel' : 'genDynamic';
  }
  /*** EVAL METHODS ENDS ***/
}