/*
===========================================================================

Unvanquished GPL Source Code
Copyright (C) 2014 Unvanquished Developers

This file is part of the Unvanquished GPL Source Code (Unvanquished Source Code).

Unvanquished Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Unvanquished Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Unvanquished Source Code.  If not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/

#ifndef IGNITABLE_COMPONENT_H_
#define IGNITABLE_COMPONENT_H_

#include "../backend/CBSEBackend.h"
#include "../backend/CBSEComponents.h"

class IgnitableComponent : public IgnitableComponentBase {
    public:
        const static float SELF_DAMAGE;
        const static float SPLASH_DAMAGE;
        const static float SPLASH_DAMAGE_RADIUS;
        const static int MIN_BURN_TIME;
        const static int STOP_CHECK_TIME;
        const static float STOP_CHANCE;
        /** Every burning entity in this radius results in a stop chance reduction factor with
         *  a size that increases linearly from STOP_CHANCE to 1 depending on entity distance. */
        const static float STOP_RADIUS;
        const static int SPREAD_CHECK_TIME;
        /** Fire spread chance decreases linearly from 1.0 to 0.0 over this distance. */
        const static float SPREAD_RADIUS;

        /////////////////////// //
        // Autogenerated Members //
        /////////////////////// //

        /**
         * @brief Default constructor of the IgnitableComponent.
         * @param entity The entity that owns the component instance.
         * @param alwaysOnFire An initialization parameter.
         * @param r_ThinkingComponent A ThinkingComponent instance that this component depends on.
         * @note This method is an interface for autogenerated code, do not modify its signature.
         */
        IgnitableComponent(Entity& entity, bool alwaysOnFire, ThinkingComponent& r_ThinkingComponent);

        /**
         * @brief Handle the PrepareNetCode message.
         * @note This method is an interface for autogenerated code, do not modify its signature.
         */
        void HandlePrepareNetCode();

        /**
         * @brief Handle the Ignite message.
         * @param fireStarter
         * @note This method is an interface for autogenerated code, do not modify its signature.
         */
        void HandleIgnite(struct gentity_s* fireStarter);

        /**
         * @brief Handle the Extinguish message.
         * @param immunityTime
         * @note This method is an interface for autogenerated code, do not modify its signature.
         */
        void HandleExtinguish(int immunityTime);

        /////////////////////// //

        void DamageSelf(int timeDelta);
        void DamageArea(int timeDelta);
        void ConsiderStop(int timeDelta);
        void ConsiderSpread(int timeDelta);

    private:
        bool onFire;
        int igniteTime;
        int immuneUntil; /**< Fire immunity time after being extinguished. */
        gentity_t* fireStarter; /**< Client who orginally started the fire. */
};

#endif // IGNITABLE_COMPONENT_H_
