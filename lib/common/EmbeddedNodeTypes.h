#pragma once

/**
 * @file EmbeddedNodeTypes.h
 * @brief Defines common data types used by the EmbeddedNodeLibs.
 */

/**
 * @brief Time duration in milliseconds.
 *
 * Used for timeouts and polling intervals.
 * Matches the return type of Arduino's millis() function.
 */
using Milliseconds = unsigned long;