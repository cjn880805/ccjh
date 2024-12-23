//xy_licanghai1.h ��׺������꣩
//�ز� 2002��12��12

NPC_BEGIN(CNxy_licanghai1);

virtual void create()
{    
    set_name("��׺�", "li cang hai");
    set("long","�����겻����ò������۷ǳ����ƣ�ֻ���������Զ���һ��СС���룬΢Ц֮�У����¶������ǳǳ�ľ��ѣ�����һ���崿�ɰ�֮����");	
    set("gender", "Ů��"); 
    set("title","��ң��");
	set("age", 14);

    set("str", 16); 
    set("int", 16);
    set("con", 30);
    set("dex", 30);
    set("per", 40);
    set("icon",5);
	create_family("��ң��", 1, "����");

    set("max_hp", 10000);
    set("mp", 5000);
    set("max_mp", 5000);
    set("mp_factor", 30); 
    set("combat_exp", 500000); 
	
	set("no_kill",1);

    set_skill("force", 100);
    set_skill("beiming_shengong", 100);
    set_skill("dodge", 100);
    set_skill("lingboweibu", 100);
    set_skill("unarmed", 100);
    set_skill("liuyang_zhang", 100);
    set_skill("parry", 100);
    set_skill("blade", 100);
    set_skill("xiaoyao_dao", 100);
    set_skill("hanzhemei_shoud", 100);
    
    map_skill("force", "beiming_shengong");
    map_skill("dodge", "lingboweibu");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "xiaoyao_dao");
    map_skill("blade", "xiaoyao_dao");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
    set("apply/armor", 100);
    set("apply/damage", 50);
    carry_object("gangdao")->wield();

	set("chat_chance", 30);
	set("no_huan",1);
	set("no_kill",1);

}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "�׻�����ѥ") && EQUALSTR(ob->querystr("base_name"), "baihu_xue") 
		&& me->query("xy/renwu4_5") && !me->query("xy/renwu4_64") &&!me->query("xy/renwu6"))
	{
		if(EQUALSTR(me->querystr("family/family_name"), "��ң��"))
		{
			tell_object(me,"\n$HIR��׺�����Ц��������Ҫ�Ǵ�����Ь�ӣ�����׽ס���ٺ���������");
		}
		else
		{
			tell_object(me,"\n$HIR��׺�����Ц������������лл��ѽ����˵��ʦ��Ҫ������ң�����أ���ѽ��͸����ðɣ���");
			load_item("sword_3")->move(me);
		}
		me->set("xy/renwu4_64",1);//�׻�����ѥ�͸���׺�
		destruct(ob);
		return 1;
	}
	return 0;
}

virtual char * chat_msg()
{
	if(querystr("owner")[0])
	{
		CContainer * env = environment();
		CContainer * xiaoyaozi=env->present(querystr("owner"));
		if(!xiaoyaozi)
		{
			add("waring",1);
			if(query("waring")>2)
				destruct(this);
		}
		else
			del("waring");
	}
	return 0;
}

NPC_END;




