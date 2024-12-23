//blade_2.h
//宝刀
//Lanwood 2001-02-03

EQUIP_BEGIN(CIblade_2);

virtual void create(int nFlag = 0)	
{
	static struct{
		char name[20];
		char id[20];
		int  damage;			//伤害力
		char apply[20];	   		//附加属性
		int	 apply_value;		//附加值
		LONG val;				//价值
		LONG weight;			//重量
		int  lvl;				//装备等级限制
	} jian[8] = {
		{"长柄窄刃刀", "long blade", 180, "str", 5, 1000, 10000, 48,},
		{"垓下刀", "wang blade", 200, "str", 5, 1500, 12000, 50,},
		{"天缺古月寒", "guyuehan",  220, "dex", 5, 2000, 10000, 55,},
		{"天涯明月", "Moon Blade", 250, "int", 6, 2500, 18000, 60,},
		{"小楼一夜听春雨", "Spring blade", 280, "str", 8, 3000, 20000, 70,},
		{"一晚十次刀", "Tiger blade", 10, "str", 30, 0, 30000, 70,},
		{"清雪流光斩", "Snow blade", 300, "int", 15, 3500, 2000, 90,},
		{"大风刀", "Wind blade", 350, "str", 15, 4000, 50000, 100,},
	};

	int lvl = random(8);

	if(nFlag) lvl = nFlag - 1;

	set_name( jian[lvl].name, jian[lvl].id);
	set("index", lvl + 1);
	
	set("wield_position", WIELD_RIGHT_HAND);
	set("skill_type", "blade");
	set_weight(jian[lvl].weight);
		
	set("unit", "柄");
	set("value", jian[lvl].val);
	set("material", "steel");
	set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。");
	set("unwield_msg", "$N将手中的$n插回刀鞘。");
	set("apply/damage", jian[lvl].damage);	
	set("equip_lvl", jian[lvl].lvl);

	set("duration", 100);
	
	/*
	if(jian[lvl].apply_value)
	{
		char str[40];
		set(snprintf(str, 40, "apply/%s", jian[lvl].apply), jian[lvl].apply_value);
	}

	if(lvl == 5) set("apply/dex", 30);
	if(lvl == 6) set("apply/dex", 10);
	if(lvl == 6) set("apply/dodge", 10);
	if(lvl == 7) set("apply/int", 3);
	if(lvl == 7) set("apply/dex", 5);
*/
};

const char * hit_ob(CChar *me, CChar *victim, LONG damage_bonus)
{
	if(add("duration", -1) <= 0)
	{
		call_out(destruct_me, 1);
		return "$HIC$w在$n身上化成一道青光，消散不见了……$COM";
	}
	
	return 0;
}

EQUIP_END;