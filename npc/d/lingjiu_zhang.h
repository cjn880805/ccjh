//lingjiu_zhang.c
//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNlingjiu_zhang);

virtual void create()
{
	set_name("�",  "zhang" );
	set("race", "Ұ��");
	set("age", 2);
	set("long", "һͷ�ɰ���⯣�����Ѫ�Ǵ�֮�");
	set("attitude", "peaceful");
	set("combat_exp", 3000);
	
	set("str", 30);
	set("cor", 26);
	
	set_temp("apply/attack", 50);
	set_temp("apply/damage", 10);
	set_temp("apply/defence",30);
	set_temp("apply/armor",10);
	
}

NPC_END;