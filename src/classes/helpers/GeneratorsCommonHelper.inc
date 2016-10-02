<?php

require_once OOP_PATH . '/src/classes/helpers/HelperBase.inc';
require_once GENERATOR_PATH . '/src/traits/helpers/BuildHelp.inc';
require_once GENERATOR_PATH . '/src/traits/helpers/StructureHelp.inc';
require_once GENERATOR_PATH . '/src/traits/helpers/ModelHelp.inc';
require_once GENERATOR_PATH . '/src/traits/helpers/KiHelp.inc';

/**
 * Class GeneratorsCommonHelper
 */
class GeneratorsCommonHelper extends HelperBase {
  use
    BuildHelp,
    StructureHelp,
    ModelHelp;

  /**
   * Guesses the structure generation method.
   *
   * @return string
   */
  public function structGenMethodGuess() {
    $dt = $this->getDataHolder();

    return $dt->__isset('model') ? 'genFromModel' : 'genDynamic';
  }
}