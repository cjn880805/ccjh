//jiaotu.h
//code by zwb
//12-16
//inherit F_MASTER;


NPC_BEGIN(CNHeiMUYa_jiaotu);

virtual void create()
{
	int age;

	age=20+random(10);

	set_name("������̽�ͽ","jiao tu");
 	set("icon",old_man1);

	set("gender", "����");
	set("age", age);
	set_skill("unarmed", 20);
	set_skill("dodge", 20);	
    set("apply/attack", 20);
	set("apply/defense", 20);
	set("apply/damage", 5);
	set("combat_exp", 550+age*10);
	set("shen_type", -1);
	add_money(10+age/10);
}


virtual char * greeting(CChar * player)
{
	return "������̣��ճ�������������⡣";
}


NPC_END