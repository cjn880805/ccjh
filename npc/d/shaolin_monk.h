// shaolin_monk.c

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNshaolin_monk);

virtual void create()
{
	set_name("��ü��ʦ",  "huangmei dashi" );
	set("age", 69);
	set("gender", "����");
	set("long", "����һ���������ơ����θߴ����ɮ������ɮ������콣ü��ʮ���������黨�����֡�");
    set("attitude", "peaceful");
	set("class", "bonze");
        set("icon",old_man2);
	
	set("age", 69);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 13);
	set("max_hp", 4500);
	set("hp", 1500);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 150);
	set("combat_exp", 1000000);
	
	set_skill("force", 110);
	set_skill("hunyuan_yiqi", 110);
	set_skill("dodge", 110);
	set_skill("shaolin_shenfa", 110);
	set_skill("finger", 110);
	set_skill("strike", 110);
	set_skill("hand", 110);
	set_skill("claw", 110);
	set_skill("parry", 110);
	set_skill("nianhua_zhi", 110);
	set_skill("sanhua_zhang", 110);
	set_skill("fengyun_shou", 110);
	set_skill("longzhua_gong", 110);
	set_skill("buddhism", 110);
	set_skill("literate", 110);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("finger", "nianhua_zhi");
	map_skill("strike", "sanhua_zhang");
	map_skill("hand", "fengyun_shou");
	map_skill("claw", "longzhua_gong");
	map_skill("parry", "nianhua_zhi");
	
	prepare_skill("finger", "nianhua_zhi");
	prepare_skill("strike", "sanhua_zhang");
 	
	carry_object("cloth")->wear();
	carry_object("bu_shoes")->wear();
	carry_object("muyu")->wield();
	
	set_inquiry("��ľ����",savemu);
}

static char * savemu(CNpc * who, CChar * me)
{
//	CContainer * obj;
	
/*	if(obj = present("duan yanqing", environment(this_object()) ) )
	{
		me->say(" �ðɣ����ý�ҩ��ľ���������ס�����졣");
		kill_ob(obj);
		obj->kill_ob(this);
	} 
*/
	CChar * duan;
	if ( (duan =(CChar *)(who->environment())->present("duan yanqing"))) 
	{
		who->say("�ðɣ����ý�ҩ��ľ���������ס�����졣");
		who->kill_ob(duan);
	} 
	else
		who->say("ľ���������棬���ý�ҩ������");
	return "";
}

NPC_END;