//lingjiu_lu.c
//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNlingjiu_lu);

virtual void create()
{
	set_name("÷��¹", "meihua lu");
	set("race", "Ұ��");
	set("age", 2);
	set("long", "һֻ�ɰ���÷��¹������Ѫ�Ǵ�֮�");
	set("attitude", "peaceful");
	
	set("str", 30);
	set("cor", 26);
	
 	set("combat_exp", 3000);
	
	set_temp("apply/attack", 50);
	set_temp("apply/damage", 10);
	set_temp("apply/defence",30);
	set_temp("apply/armor",10);
	
}

NPC_END;