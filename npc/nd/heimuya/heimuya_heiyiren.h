//heiyiren.h
//code by zwb
//12-16
//inherit F_MASTER;


NPC_BEGIN(CNHeiMUYa_heiyiren);

virtual void create()
{

	set_name("������","hei yi ren");

	set("icon", young_man1);
	set("gender", "����");
	set("age", 25);
	set("title", "������̷����õ���");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);	
	set("apply/attack", 50);
	set("apply/defense", 50);
	set("apply/damage", 25);
	set("combat_exp", 30000);
	set("shen_type", -1);
}

NPC_END;