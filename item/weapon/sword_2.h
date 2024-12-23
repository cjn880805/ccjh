//sword_2.h
//宝剑
//Lanwood 2001-02-03

EQUIP_BEGIN(CIsword_2);

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
		int lvl;
	} jian[8] = {
		{"碧血剑", "bixue jian", 50, "str", 2, 500, 10000, 10,},
		{"鱼肠剑", "yuchang jian", 50, "str", 4, 650, 12000, 12,},
		{"玉女剑", "yunv jian",  60, "dex", 3, 680, 8000, 13,},
		{"君子剑", "junzi jian", 70, "int", 3, 750, 15000, 14,},
		{"淑女剑", "shunv jian", 80, "dex", 4, 750, 12000, 14,},
		{"玄铁剑", "xuantie jian", 90, "str", 5, 800, 30000, 15,},
		{"青虹剑", "tie jian", 100, "str", 5, 850, 20000, 15,},
		{"青龙剑", "dragon sword", 120, "str", 5, 900, 18000, 15,},
	};

	int lvl = random(8);

	if(nFlag) lvl = nFlag - 1;

	set_name( jian[lvl].name, jian[lvl].id);
	set("index", lvl + 1);
	
	set("wield_position", WIELD_RIGHT_HAND);
	set("skill_type", "sword");
	set_weight(jian[lvl].weight);
		
	set("unit", "柄");
	set("value", jian[lvl].val);
	set("material", "steel");
	set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。");
	set("unwield_msg", "$N将手中的$n插回剑鞘。");
	set("apply/damage", jian[lvl].damage );	
	set("equip_lvl", jian[lvl].lvl);

	set("duration", 150);
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
		return "$HIR$w在$n身上化成一道红光，消散不见了……$COM";
	}
	
	return 0;
}

EQUIP_END;