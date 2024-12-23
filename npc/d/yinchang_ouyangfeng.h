//yinchang_ouyangfeng.c

//code by Fisho
//date:2000-12-23
//inherit F_MASTER;

NPC_BEGIN(CNyinchang_ouyangfeng);

virtual void create()
{
	set_name("����ׯ��",  "ouyang feng");
	set("long", "���ǰ���ɽ��ׯ�������ڱ��ض���ƭ��ͻȻ�߻���ħ���ѱ�þ�����ң�������ͷɢ����");
	set("title", "����ɽׯ��");
	set("gender", "����");
	set("age", 53);
        set("icon",old_man1);

	set("nickname",  "����" );
	set("shen_type",-1);
	set("repute", -150000);
	set("attitude", "peaceful");
	
	set("str", 30);
	set("int", 29);
	set("con", 30);
	set("dex", 28);
	
	set("hp", 2500);
	set("max_hp", 7500);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 50);
	
	set("combat_exp", 1500000);
	set("score", 200000);
	
	set_skill("force", 200);
	set_skill("unarmed", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("hand",170);
	set_skill("staff", 170);
	set_skill("hamagong", 200);
	set_skill("chanchu_bufa", 170);
	set_skill("shexing_diaoshou", 170);
	set_skill("lingshe_zhangfa", 170);
	
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu_bufa");
	map_skill("unarmed", "shexing_diaoshou");
	map_skill("hand", "shexing_diaoshou");
	map_skill("parry", "lingshe_zhangfa");
	map_skill("staff", "lingshe_zhangfa");
	
	create_family("����ɽ��",1, "��ɽ��ʦ");

	carry_object("gangzhang")->wield();
	carry_object("cloth")->wear();
	add_money(5000);
}
/*
virtual char * greeting(CChar * ob)
{
	CContainer *obj;//, me=this_object();
	int i;
	
	obj = all_inventory(me->environment());
	say(" ʮ��һ�ˣ��ٲ�ʮ�ˣ��������ޣ����ɱ�ء�");
	command("consider");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="ding-chunqiu")
		{
			Do_Attack(this, ob, 0 );
			Do_Attack(this, ob, 0 );
		}
	}
	return "";
}
*/

NPC_END;