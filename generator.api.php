<?php

/**
 * @file
 *
 * This file provides with the module's API documentation.
 */

/**
 * Declares a generator.
 *
 * @return array
 */
function hook_generator_info() {
  $info           = array();
  $info['sys_id'] = array(
    'class alter' => array(
      'model'          => array(
        'class' => '%args%Generator%fieldable%',
      ),
      'dependency dir' => 'dir'
    ),
  );

  return $info;
}

/**
 * Declares a builder.
 *
 * @return array
 */
function hook_builder_info() {
  $info           = array();
  $info['sys_id'] = array(
    'class alter' => array(
      'model'          => array(
        'class' => '%args%Builder%fieldable%',
      ),
      'dependency dir' => 'dir'
    ),
  );

  return $info;
}

/**
 * Declares a model.
 *
 * @return array
 */
function hook_model_info() {
  $info           = array();
  $info['sys_id'] = array(
    'class alter' => array(
      'model'          => array(
        'class' => '%args%Model%fieldable%',
      ),
      'dependency dir' => 'dir',
    ),
  );

  return $info;
}

/**
 * Declares a Ki.
 *
 * @return array
 */
function hook_ki_info() {
  $info           = array();
  $info['sys_id'] = array(
    'class alter' => array(
      'model'          => array(
        'class' => '%args%Ki%fieldable%',
      ),
      'dependency dir' => 'dir'
    ),
  );

  return $info;
}