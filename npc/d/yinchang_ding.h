// yinchang_ding.c ������

//code by Fisho
//date:2000-12-23
//inherit F_MASTER;

NPC_BEGIN(CNyinchang_ding);

virtual void create()
{
	set_name("������",  "ding chunqiu");
	set("nickname", "�����Ϲ�");
	set("long","�����������ɿ�ɽ��ʦ����������ʿ���ʹ���������Ϲֶ����ɡ���������������ò���棬�ɷ���ǡ�");
	set("gender", "����");
	set("age", 60);
        set("icon",old_man1);

	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", -1);
	set("repute", -150000);
	set("str", 25);
	set("int", 30);
	set("con", 28);
	set("dex", 28);
	
	set("max_hp", 12000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 100);
	set("combat_exp", 1500000);
	set("score", 400000);
	
	set_skill("force", 100);
	set_skill("huagong_dafa", 150);
	set_skill("throwing", 150);
	set_skill("feixing_shu", 150);
	set_skill("dodge", 150);
	set_skill("zhaixinggong", 150);
	set_skill("unarmed", 100);
	set_skill("chousui_zhang", 150);
	set_skill("claw", 100);
	set_skill("sanyin_wugongzhao", 150);
	set_skill("parry", 100);
	set_skill("staff", 100);
	set_skill("poison", 100);
	set_skill("tianshan_zhang", 150);
	//	set_skill("literate", 80);
	
	map_skill("force", "huagong_dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("unarmed", "chousui_zhang");
	map_skill("claw", "sanyin_wugongzhao");
	map_skill("parry", "tianshan_zhang");
	map_skill("staff", "tianshan_zhang");
	
	create_family("������", 1, "��ɽ��ʦ");
	set("class", "taoist");
	
//  carry_object("changjian")->wield();
}
/*
virtual char * greeting(CChar * ob)
{
	CContainer *obj;//, me=this_object();
	int i;
	
	obj = all_inventory(me->environment());
	say(" ʮ��ɱһ�ˣ������ɾ����񹦾�Ҫ���̡�");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="ouyang-feng")
		{
			Do_Attack(this, ob, 0 );
			Do_Attack(this, ob, 0 );
		}
	}
	return "";
}
*/

NPC_END;