//armor_1.h

EQUIP_BEGIN(CIarmor_1);

virtual void create(int nFlag = 0)	
{
	static struct{
		char name[12], id[20];
		int wield_position;
		LONG  weight, value;
		int armor;
		char attr[20];
		int modify;
	}armor[14]={
		{"乌龟甲", "wugui jia", WIELD_ARMOR, 2000, 500, 5, "", 0},
		{"疾风靴", "boot", WIELD_BOOT, 5000, 1500, 2, "dodge", 5},
		{"花头巾", "tou jin", WIELD_HEAD, 1000, 500, 2, "per", 1},
		{"鹿皮手套", "shou tao", WIELD_ARMOR_HANDS, 2800, 500, 10, "defense", 1},
		{"虎皮手套", "shou tao", WIELD_ARMOR_HANDS, 3000, 500, 15, "defense", 1},
		{"熊皮手套", "shou tao", WIELD_ARMOR_HANDS, 3500, 500, 20, "defense", 2},
		{"狗皮帽", "pi mao", WIELD_HEAD, 500, 100, 3, "", 0},
		{"虎纹披风", "pi feng", WIELD_MANTLE, 500, 1500, 3, "armor_vs_force", 10},
		{"豹纹披风", "pi feng", WIELD_MANTLE, 800, 1500, 5, "armor_vs_force", 20},
		{"大红披风", "pi feng", WIELD_MANTLE, 1000, 1500, 8, "armor_vs_force", 30},
		{"朱红披风", "pi feng", WIELD_MANTLE, 300, 500, 2, "armor_vs_force", 50},
		{"鹿皮靴", "pi xue", WIELD_BOOT, 300, 500, 2, "dodge", 1},
		{"铁靴", "tie xue", WIELD_BOOT, 1500, 500, 20, "dodge", -5},
		{"铁手套", "shou tao", WIELD_ARMOR_HANDS, 1500, 5500, 30, "attack", -5},
	};

	int idx = random(14);
	if(nFlag) idx = nFlag - 1;

	set("index", idx + 1);
	set_name(armor[idx].name, armor[idx].id);	

	set("wield_position", armor[idx].wield_position);	
 	set_weight(armor[idx].weight);	
         
	set("unit", "件");
	set("value", armor[idx].value);
		
	set("apply/armor", armor[idx].armor);
	if(armor[idx].modify)
	{
		char key[40];
		
		snprintf(key, 40, "apply/%s", armor[idx].attr);
		set(key, armor[idx].modify);		
	}
	
	set("wear_msg","$N穿上$n。");
	set("remove_msg","$N将$n脱了下来。");
};

EQUIP_END;
