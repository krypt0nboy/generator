<?php

/**
 * Class KiHelper
 */
class KiHelper extends HelperBase {
  use
    OopCommon,
    BuildHelperMethods,
    StructureHelperMethods {
    OopCommon::setUp as oopSetUp;
  }
}