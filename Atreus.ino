/* -*- mode: c++ -*-
 * Atreus -- Chrysalis-enabled Sketch for the Keyboardio Atreus
 * Copyright (C) 2018-2022  Keyboard.io, Inc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

 // vim: et ts=2 sw=0 sts=0

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built on " __DATE__ " at " __TIME__
#endif

#include <Kaleidoscope.h>
#include <Kaleidoscope-DynamicMacros.h>
#include <Kaleidoscope-EEPROM-Keymap.h>
#include <Kaleidoscope-EEPROM-Settings.h>
#include <Kaleidoscope-Escape-OneShot.h>
#include <Kaleidoscope-FirmwareVersion.h>
#include <Kaleidoscope-FocusSerial.h>
#include <Kaleidoscope-LayerNames.h>
#include <Kaleidoscope-Macros.h>
#include <Kaleidoscope-MouseKeys.h>
#include <Kaleidoscope-OneShot.h>
#include <Kaleidoscope-Qukeys.h>

enum {
  MACRO_QWERTY,
  MACRO_VERSION_INFO
};

#define Key_Exclamation LSHIFT(Key_1)
#define Key_At          LSHIFT(Key_2)
#define Key_Hash        LSHIFT(Key_3)
#define Key_Dollar      LSHIFT(Key_4)
#define Key_Percent     LSHIFT(Key_5)
#define Key_Caret       LSHIFT(Key_6)
#define Key_And         LSHIFT(Key_7)
#define Key_Star        LSHIFT(Key_8)
#define Key_Plus        LSHIFT(Key_Equals)

#define Key_DoubleQuote LSHIFT(Key_Quote)
#define Key_Tilde       LSHIFT(Key_Backtick)
#define Key_Underscore  LSHIFT(Key_Minus)

#define _______  XXX

#define _PLAY_   Consumer_PlaySlashPause
#define _NEXT_   Consumer_ScanNextTrack
#define _PREV_   Consumer_ScanPreviousTrack
#define _VOLU_   Consumer_VolumeIncrement
#define _VOLD_   Consumer_VolumeDecrement

#define _ALT_    Key_LeftAlt
#define _BKSP_   Key_Backspace
#define _BSLSH_  Key_Backslash
#define _BKTCK_  Key_Backtick
#define _COMMA_  Key_Comma
#define _CTRL_   Key_LeftControl
#define _DEL_    Key_Delete
#define _DOT_    Key_Period
#define _DQUOT_  Key_DoubleQuote
#define _END_    Key_End
#define _ENTER_  Key_Enter
#define _EQL_    Key_Equals
#define _ESC_    Key_Escape
#define _GUI_    Key_LeftGui
#define _HOME_   Key_Home
#define _INS_    Key_Insert
#define _MINUS_  Key_Minus
#define _PGUP_   Key_PageUp
#define _PGDN_   Key_PageDown
#define _PIPE_   Key_Pipe
#define _PLUS_   Key_Plus
#define _QUOTE_  Key_Quote
#define _SHIFT_  Key_LeftShift
#define _SLASH_  Key_Slash
#define _SMCLN_  Key_Semicolon
#define _SPACE_  Key_Space
#define _TAB_    Key_Tab
#define _TILDE_  Key_Tilde
#define _UNDSC_  Key_Underscore

#define _LPRN_   Key_LeftParen
#define _RPRN_   Key_RightParen
#define _LBRC_   Key_LeftBracket
#define _RBRC_   Key_RightBracket
#define _LCBR_   Key_LeftCurlyBracket
#define _RCBR_   Key_RightCurlyBracket

#define _LEFT_   Key_LeftArrow
#define _RIGHT_  Key_RightArrow
#define _DOWN_   Key_DownArrow
#define _UP_     Key_UpArrow

#define _CTL_C_  LCTRL(Key_C)
#define _CTL_F_  LCTRL(Key_F)
#define _CTL_V_  LCTRL(Key_V)
#define _CTL_X_  LCTRL(Key_X)
#define _CTL_Z_  LCTRL(Key_Z)

#define _LOCK_   LCTRL(LGUI(Key_Q))
#define _UNDO_   LGUI(Key_Z)
#define _CUT_    LGUI(Key_X)
#define _COPY_   LGUI(Key_C)
#define _PASTE_  LGUI(Key_V)

#define MO(n)    ShiftToLayer(n)
#define TG(n)    LockLayer(n)

enum {
  QWERTY,
  NAVIGATION,
  NUMBER,
  CONTROL,
  FUNCTION,
};

#define __CTL__  MO(CONTROL)
#define __FUN__  MO(FUNCTION)
#define __NAV__  MO(NAVIGATION)
#define __NUM__  MO(NUMBER)

// clang-format off
KEYMAPS(

  // =============================================================================
  // QWERTY
  // =============================================================================
  [QWERTY] = KEYMAP_STACKED
  (
    Key_Q  ,Key_W  ,Key_E  ,Key_R  ,Key_T  ,
    Key_A  ,Key_S  ,Key_D  ,Key_F  ,Key_G  ,
    Key_Z  ,Key_X  ,Key_C  ,Key_V  ,Key_B  ,_______,
    _LOCK_ ,_______,_______,__CTL__,__NUM__,__NAV__,

            Key_Y  ,Key_U  ,Key_I  ,Key_O  ,Key_P,
            Key_H  ,Key_J  ,Key_K  ,Key_L  ,_SMCLN_,
    _BKSP_ ,Key_N  ,Key_M  ,_COMMA_,_DOT_  ,_SLASH_,
    _SHIFT_,_SPACE_,__FUN__,_______,_______,_______
  ),

  // =============================================================================
  // NAVIGATION
  // =============================================================================
  [NAVIGATION] = KEYMAP_STACKED
  (
    _ESC_  ,_DEL_  ,_PGUP_ ,_PGDN_ ,_HOME_ ,
    _ENTER_,_GUI_  ,_ALT_  ,_CTRL_ ,_BKSP_ ,
    _CTL_Z_,_CTL_X_,_CTL_C_,_CTL_V_,_END_  ,_______,
    _______,_______,_______,_______,_______,_______,

            _______,_______,_INS_  ,_______,_______,
            _LEFT_ ,_DOWN_ ,_UP_   ,_RIGHT_,_TAB_  ,
    _______,_______,_______,_______,_______,_CTL_F_,
    _SHIFT_,_______,_______,_______,_______,_______
  ),

  // =============================================================================
  // NUMBER
  // =============================================================================
  [NUMBER] = KEYMAP_STACKED
  (
    _TILDE_,Key_9  ,Key_8  ,Key_7  ,_______,
    Key_0  ,Key_3  ,Key_2  ,Key_1  ,_______,
    _BKTCK_,Key_6  ,Key_5  ,Key_4  ,_______,_______,
    _______,_______,_______,_______,_______,_______,

            _______,_LPRN_ ,_RPRN_ ,_BSLSH_,_PIPE_ ,
            _DQUOT_,_LCBR_ ,_RCBR_ ,_MINUS_,_UNDSC_,
    _______,_QUOTE_,_LBRC_ ,_RBRC_ ,_EQL_  ,_PLUS_ ,
    _SHIFT_,_______,_______,_______,_______,_______
  ),

  // =============================================================================
  // CONTROL
  // =============================================================================
  [CONTROL] = KEYMAP_STACKED
  (
    _______              ,_VOLU_ ,_VOLD_ ,_______,_______,
    _______              ,_PREV_ ,_PLAY_ ,_NEXT_ ,_______,
    M(MACRO_VERSION_INFO),_______,_______,_______,_______,_______,
    MoveToLayer(QWERTY)  ,_______,_______,_______,_______,_______,

            _______,Key_F7 ,Key_F8 ,Key_F9 ,Key_F10,
            _______,Key_F4 ,Key_F5 ,Key_F6 ,Key_F11,
    _______,_______,Key_F1 ,Key_F2 ,Key_F3 ,Key_F12,
    _SHIFT_,_______,_______,_______,_______,_______
  ),

  // =============================================================================
  // FUNCTION
  // =============================================================================
  [FUNCTION] = KEYMAP_STACKED
  (
    Key_F12,Key_F9 ,Key_F8 ,Key_F7 ,_______,
    Key_F10,Key_F3 ,Key_F2 ,Key_F1 ,_______,
    Key_F11,Key_F6 ,Key_F5 ,Key_F4 ,_______,_______,
    _______,_______,_______,_______,_______,_______,

            _______,_______,_______,_______,_______,
            _______,_CTRL_ ,_ALT_  ,_GUI_  ,_SHIFT_,
    _______,_______,_______,_______,_______,_______,
    _SHIFT_,_______,_______,_______,_______,_______
  )
)
// clang-format on



KALEIDOSCOPE_INIT_PLUGINS(
  // ----------------------------------------------------------------------
  // Chrysalis plugins

  // The EEPROMSettings & EEPROMKeymap plugins make it possible to have an
  // editable keymap in EEPROM.
  EEPROMSettings,
  EEPROMKeymap,

  // Focus allows bi-directional communication with the host, and is the
  // interface through which the keymap in EEPROM can be edited.
  Focus,

  // FocusSettingsCommand adds a few Focus commands, intended to aid in
  // changing some settings of the keyboard, such as the default layer (via the
  // `settings.defaultLayer` command)
  FocusSettingsCommand,

  // FocusEEPROMCommand adds a set of Focus commands, which are very helpful in
  // both debugging, and in backing up one's EEPROM contents.
  FocusEEPROMCommand,

  // The FirmwareVersion plugin lets Chrysalis query the version of the firmware
  // programmatically.
  FirmwareVersion,

  // The LayerNames plugin allows Chrysalis to display - and edit - custom layer
  // names, to be shown instead of the default indexes.
  LayerNames,

  // ----------------------------------------------------------------------
  // Keystroke-handling plugins

  // The Qukeys plugin enables the "Secondary action" functionality in
  // Chrysalis. Keys with secondary actions will have their primary action
  // performed when tapped, but the secondary action when held.
  Qukeys,

  // Enables the "Sticky" behavior for modifiers, and the "Layer shift when
  // held" functionality for layer keys.
  OneShot,
  OneShotConfig,
  EscapeOneShot,
  EscapeOneShotConfig,

  // The macros plugin adds support for macros
  Macros,

  // Enables dynamic, Chrysalis-editable macros.
  DynamicMacros,

  // The MouseKeys plugin lets you add keys to your keymap which move the mouse.
  MouseKeys,
  MouseKeysConfig  //,

  // The MagicCombo plugin lets you use key combinations to trigger custom
  // actions - a bit like Macros, but triggered by pressing multiple keys at the
  // same time.
  // MagicCombo,

  // Enables the GeminiPR Stenography protocol. Unused by default, but with the
  // plugin enabled, it becomes configurable - and then usable - via Chrysalis.
  // GeminiPR,
);

const macro_t *macroAction(uint8_t macro_id, KeyEvent &event) {
  if (keyToggledOn(event.state)) {
    switch (macro_id) {
    case MACRO_QWERTY:
      // This macro is currently unused, but is kept around for compatibility
      // reasons. We used to use it in place of `MoveToLayer(QWERTY)`, but no
      // longer do. We keep it so that if someone still has the old layout with
      // the macro in EEPROM, it will keep working after a firmware update.
      Layer.move(QWERTY);
      break;
    case MACRO_VERSION_INFO:
      Macros.type(PSTR("Keyboardio Atreus - Kaleidoscope "));
      Macros.type(PSTR(BUILD_INFORMATION));
      break;
    default:
      break;
    }
  }
  return MACRO_NONE;
}

void setup() {
  Kaleidoscope.setup();
  EEPROMKeymap.setup(9);

  DynamicMacros.reserve_storage(48);

  LayerNames.reserve_storage(63);

  Layer.move(EEPROMSettings.default_layer());
}

void loop() {
  Kaleidoscope.loop();
}

