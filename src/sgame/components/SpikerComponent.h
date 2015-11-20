#ifndef SPIKER_COMPONENT_H_
#define SPIKER_COMPONENT_H_

#include "../backend/CBSEBackend.h"
#include "../backend/CBSEComponents.h"

class SpikerComponent : public SpikerComponentBase {
    public:
        /////////////////////// //
        // Autogenerated Members //
        /////////////////////// //

        /**
         * @brief Default constructor of the SpikerComponent.
         * @param entity The entity that owns the component instance.
         * @param r_AlienBuildableComponent A AlienBuildableComponent instance that this component depends on.
         * @note This method is an interface for autogenerated code, do not modify its signature.
         */
        SpikerComponent(Entity& entity, AlienBuildableComponent& r_AlienBuildableComponent);

        /**
         * @brief Handle the Damage message.
         * @param amount
         * @param source
         * @param location
         * @param direction
         * @param flags
         * @param meansOfDeath
         * @note This method is an interface for autogenerated code, do not modify its signature.
         */
        void HandleDamage(float amount, gentity_t* source, Util::optional<Vec3> location, Util::optional<Vec3> direction, int flags, meansOfDeath_t meansOfDeath);

        /////////////////////// //

    private:

};

#endif // SPIKER_COMPONENT_H_
