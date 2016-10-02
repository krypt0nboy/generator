<?php

/**
 * @file
 *
 * This file provides with required basic functions.
 */

/**
 * Creates and returns a Generator.
 *
 * @param string $sys_id
 *   The generator's system id.
 * @param array  $args
 *   The args.
 *
 * @return _GeneratorBase
 */
function generator($sys_id, array $args = array()) {
  /** @var GeneratorFactory $factory */
  $factory = factory('generator');

  return $factory
    ->generator_sys_id($sys_id)
    ->getInstance($args, FALSE);
}

/**
 * Creates and returns a Builder.
 *
 * @param string $sys_id
 *   The builder's system id.
 * @param array  $args
 *   The args.
 *
 * @return BuilderBase
 */
function builder($sys_id, array $args = array()) {
  /** @var BuilderFactory $factory */
  $factory = factory('builder');

  return $factory
    ->builder_sys_id($sys_id)
    ->getInstance($args, FALSE);
}

/**
 * Creates and returns a Model.
 *
 * @param string $sys_id
 *   The model's system id.
 * @param array  $args
 *   The factory args.
 *
 * @return ModelBase
 */
function model($sys_id, array $args = array()) {
  /** @var ModelFactory $factory */
  $factory = factory('model');

  return $factory
    ->model_sys_id($sys_id)
    ->getInstance($args, FALSE);
}

/**
 * Creates and returns a Ki.
 *
 * @param string $sys_id
 *   The Ki's system id.
 * @param array  $args
 *   The factory args.
 *
 * @return KiBase
 */
function ki($sys_id, array $args = array()) {
  /** @var KiFactory $factory */
  $factory = factory('ki');

  return $factory
    ->ki_sys_id($sys_id)
    ->getInstance($args, FALSE);
}

/**
 * Creates and returns a StaticKiBase.
 *
 * @param string $name
 *   The key's name.
 *
 * @return StaticKiBase
 */
function static_ki($name) {
  require_once GENERATOR_PATH . '/src/classes/static_kis/StaticKiBase.inc';
  $ki = new StaticKiBase(array('name' => $name));

  return $ki;
}