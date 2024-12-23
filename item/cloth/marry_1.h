//���װ��
//marry_1.h
//Lanwood 2001-03-17

EQUIP_BEGIN(CImarry_1);

virtual void create(int nFlag = 0)	
{
	static struct{
		char name[15], id[20];
		int wield_position;
		LONG  weight, value;
		int armor;
		char attr[10];
		int modify;

		char wear_msg[80], unwear_msg[80];
	}armor[15]={
		{"��ɫ�������", "marry dress", WIELD_ARMOR, 500, 8000, 3, "per", 3, "$YEL$N����һ��$n����ʱ�ݹ������", "$N����һ��$n��"},
		{"����������", "marry dress", WIELD_ARMOR, 500, 8500, 2, "per", 3, "$HIY$N����һ��$n����ʱ������ˡ�", "$N����һ��$n��"},
		{"����ñ", "cap", WIELD_HEAD, 800, 500, 1, "per", 1, "$N����һ��$n��", "$Nժ��$n��"},
		{"��Ȼ��ˮ������", "lace",  WIELD_NECK, 800, 1500, 1, "per", 1, "$N����һ��$n���������޶��ˡ�", "$Nȡ��һ��$nϸ���պá�"},
		{"���Ʊ�������", "lace", WIELD_NECK, 500, 2500, 1, "per", 1, "$N����һ��$n���������޶��ˡ�", "$Nȡ��һ��$nϸ���պá�"},
		{"�Ͻ���ʯ����", "lace", WIELD_NECK, 500, 3500, 1, "per", 2, "$N����һ��$n���������޶��ˡ�", "$Nȡ��һ��$nϸ���պá�"},
		{"��������", "lace", WIELD_NECK, 300, 1500, 1, "per", 1, "$N����һ��$n���������޶��ˡ�", "$Nȡ��һ��$nϸ���պá�"},
		{"�����ָ", "ring", WIELD_RING, 100, 2500, 1, "per", 1, "$N����һö$n��С�ĵ�������������ָ�ϡ�", "$Nժ��һö$n��ϸ���պá�"},
		{"�������", "wrist", WIELD_WRIST, 500, 1500, 1, "per", 1, "$N����һֻ$n��С�ĵ����������ϡ�", "$Nȡ��һֻ$n��ϸ���պá�"},
		{"���ҹ����", "ye ming zhu", WIELD_LEFT_ERR, 800, 5500, 1, "per", 2, "$N�������˵Ľ�$n��������ϡ�", "$NС�ĵ�ȡ��$n��ϸ���պá�"},

		{"���Ƕ���", "er huan", WIELD_ERR, 200, 1500, 1, "per", 1, "$Nȡ��$n���ڶ��ϡ�", "$Nժ�¶��ϵ�$n��ϸ���պá�"},
		{"�����˿����", "pi feng", WIELD_MANTLE, 300, 2500, 2, "per", 2, "$N����һ��$n��", "$N����һ��$n��"},
		{"��ɫ��ͲƤѥ", "pi xue", WIELD_BOOT, 500, 800, 2, "per", 1, "$N����һ˫$n��", "$N����һ˫$n��"},
		{"��ɫ�廨Ь", "shoes", WIELD_BOOT, 300, 500, 1, "per", 1, "$N����һ˫$n��", "$N����һ˫$n��"},
		{"�������", "waist", WIELD_WAIST, 500, 1500, 2, "per", 1, "$N��һ��$nϵ�����䡣", "$N�⿪$n��"},
	};

	int idx = random(15);
	if(nFlag) idx = nFlag - 1;

	set("index", idx + 1);
	set_name(armor[idx].name, armor[idx].id);	

	set("wield_position", armor[idx].wield_position);	
 	set_weight(armor[idx].weight);	
         
	set("unit", "��");
	set("value", armor[idx].value);
		
	set("apply/armor", armor[idx].armor);
	if(armor[idx].modify)
	{
		char key[40];
		
		snprintf(key, 40, "apply/%s", armor[idx].attr);
		set(key, armor[idx].modify);		
	}
	
	set("wear_msg", armor[idx].wear_msg);
	set("remove_msg", armor[idx].unwear_msg);
};

EQUIP_END;
