// lingjiu_jiuyi.c

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNlingjiu_jiuyi);

virtual void create()
{
	set_name("��ͷ����","jiuyi daoren");
	set("long","��������һƷ����Ƹ�ĸ���,��ĸ���,����������������,���Ṧ����,��ʹ�׹���,ƾһ���׹�������,��Ϊ������һ������.");
	set("title", "����һƷ�ø���");
	set("gender", "����");
	set("nickname",  "��������" );
	set("age", 40);
	set("shen_type",-1);
	set("attitude", "peaceful");
 	set("icon",young_man3);

	set("str", 27);
	set("int", 23);
	set("con", 24);
	set("dex", 30);
        set("icon",old_man1);

	
	set("max_hp", 3000);
 	set("hp", 1000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 0l);

	set("combat_exp", 1000000);
	set("score", 100000);
	
}

NPC_END;