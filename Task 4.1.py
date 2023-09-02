import random

class Villain:
    def __init__(self):
        self.health = 100
        self.energy = 500
        self.shield = 0

    def take_damage(self, damage):
        if self.shield > 0:
            damage_reduction = self.shield / 100.0
            damage *= (1 - damage_reduction)
        self.health -= damage

    def use_weapon(self, opponent):
        pass

    def use_shield(self):
        pass

class GruVillain(Villain):
    def __init__(self):
        super().__init__()

    def use_weapon(self, opponent):
        weapon = random.choice([FreezeGun(), ElectricProd(), MegaMagnet(), KalmanMissile()])
        weapon.use(self, opponent)

    def use_shield(self):
        shield = random.choice([EnergyProjectedBarrierGun(), SelectivePermeabilityShield()])
        shield.use(self)

class VectorVillain(Villain):
    def __init__(self):
        super().__init__()

    def use_weapon(self, opponent):
        weapon = random.choice([LaserBlasters(), PlasmaGrenades(), SonicResonanceCannon()])
        weapon.use(self, opponent)

    def use_shield(self):
        shield = random.choice([EnergyNetTrap(), QuantumDeflector()])
        shield.use(self)

class Weapon:
    def __init__(self, energy, damage):
        self.energy = energy
        self.damage = damage

    def use(self, user, opponent):
        pass

class GruWeapon(Weapon):
    def __init__(self, energy, damage):
        super().__init__(energy, damage)

class FreezeGun(GruWeapon):
    def __init__(self):
        super().__init__(50, 11)

    def use(self, user, opponent):
        opponent.take_damage(self.damage)

class ElectricProd(GruWeapon):
    def __init__(self):
        super().__init__(88, 18)

    def use(self, user, opponent):
        opponent.take_damage(self.damage)

class MegaMagnet(GruWeapon):
    def __init__(self):
        super().__init__(92, 10)

    def use(self, user, opponent):
        opponent.shield -= 20

class KalmanMissile(GruWeapon):
    def __init__(self):
        super().__init__(120, 20)

    def use(self, user, opponent):
        opponent.take_damage(self.damage)

class VectorWeapon(Weapon):
    def __init__(self, energy, damage):
        super().__init__(energy, damage)

class LaserBlasters(VectorWeapon):
    def __init__(self):
        super().__init__(40, 8)

    def use(self, user, opponent):
        opponent.take_damage(self.damage)

class PlasmaGrenades(VectorWeapon):
    def __init__(self):
        super().__init__(56, 13)

    def use(self, user, opponent):
        opponent.take_damage(self.damage)

class SonicResonanceCannon(VectorWeapon):
    def __init__(self):
        super().__init__(100, 22)

    def use(self, user, opponent):
        opponent.take_damage(self.damage)

class Shield:
    def __init__(self):
        pass

    def use(self, user):
        pass

class GruShield(Shield):
    def __init__(self):
        super().__init__()

class EnergyProjectedBarrierGun(GruShield):
    def __init__(self):
        super().__init__()

    def use(self, user):
        user.shield += 40

class SelectivePermeabilityShield(GruShield):
    def __init__(self):
        super().__init__()

    def use(self, user):
        user.shield += 90

class VectorShield(Shield):
    def __init__(self):
        super().__init__()

class EnergyNetTrap(VectorShield):
    def __init__(self):
        super().__init__()

    def use(self, user):
        user.shield += 32

class QuantumDeflector(VectorShield):
    def __init__(self):
        super().__init__()

    def use(self, user):
        user.shield += 80

def simulate_battlefield():
    gru = GruVillain()
    vector = VectorVillain()
    round_count = 1

    while gru.health > 0 and vector.health > 0:
        print("Round", round_count)
        print("Gru Health:", gru.health)
        print("Vector Health:", vector.health)

        gru.use_weapon(vector)
        vector.use_weapon(gru)

        gru.use_shield()
        vector.use_shield()

        print()

        round_count += 1

    if gru.health <=0:
        print("Vector wins!")
    else:
        print("Gru wins!")

simulate_battlefield()
