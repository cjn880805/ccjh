//blade_1.h
//宝刀
//Teapot 2001-02-03

EQUIP_BEGIN(CIblade_1);

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
		int lvl;				//装备等级
	} jian[8] = {
		{"无常", "wuchang dao", 40, "str", 2, 500, 10000, 20,},
		{"虎澈", "huche dao", 50, "str", 4, 650, 12000, 30,},
		{"福冈一文字", "fuganyi wenzi",  70, "dex", 3, 680, 8000, 35,},
		{"菊一文字", "jvyi wenzi", 70, "int", 3, 750, 15000, 40,},
		{"长船", "changchuang dao", 70, "dex", 4, 750, 12000, 40,},
		{"长光", "zhangguang dao", 80, "str", 5, 800, 30000, 43,},
		{"正恒", "zhengheng dao", 100, "str", 5, 850, 20000, 45,},
		{"寒雨", "hanyu dao", 150, "str", 5, 900, 18000, 45,},
	};

	int lvl = random(8);

	if(nFlag) lvl = nFlag - 1;

	set_name(jian[lvl].name, jian[lvl].id);
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

	if(lvl == 6) set("apply/dex", 3);
	if(lvl == 7) set("apply/dex", 4);
*/
};

const char * hit_ob(CChar *me, CChar *victim, LONG damage_bonus)
{
	if(add("duration", -1) <= 0)
	{
		call_out(destruct_me, 1);
		return "$HIM$w在$n身上化成一道紫光，消散不见了……$COM";
	}
	
	return 0;
}

EQUIP_END;