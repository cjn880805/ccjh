//xy_liqiouheng.h ����ۣ����꣩
//�ز� 2002��12��12

NPC_BEGIN(CNxy_liqiouheng);

virtual void create()
{    
    set_name("�����", "li qiou heng");
    set("long","������һϮ���Ƴ�����������֬��üĿ�续��������̬�򷽣���Ц֮�䣬һ�ɽ���̬֮��Ȼ������");	
    set("gender", "Ů��"); 
    set("age", 20);

    set("str", 20); 
    set("int", 20);
    set("con", 28);
    set("dex", 30);
    set("per", 40);

    set("icon",6);
	set("title","��ң��");
	create_family("��ң��", 1, "����");

    set("max_hp", 18000);
    set("mp", 9000);
    set("max_mp", 9000);
    set("mp_factor", 120); 
    set("combat_exp", 5000000); 

	set("chat_chance", 30);
	
	set("no_kill",1);

    set_skill("force", 300);
    set_skill("xiaowuxiang", 300);
    set_skill("dodge", 300);
    set_skill("xiaoyao_bu", 300);
    set_skill("unarmed", 300);
    set_skill("liuyang_zhang", 300);
    set_skill("parry", 300);
    set_skill("blade", 300);
    set_skill("xiaoyao_dao", 300);
    set_skill("zhemei_shou", 300);
    set_skill("hand", 300);
	set_skill("literate", 280);
    
    map_skill("force", "xiaowuxiang");
    map_skill("dodge", "xiaoyao_bu");
    map_skill("hand", "zhemei_shou");
    map_skill("unarmed", "liuyang_zhang");
    map_skill("parry", "xiaoyao_dao");
    map_skill("blade", "xiaoyao_dao");
    
    prepare_skill("hand","zhemei_shou");
    prepare_skill("unarmed","liuyang_zhang");
    set("apply/armor", 200);
    set("apply/damage", 150);
    carry_object("gangdao")->wield();
	set("no_huan",1);

}

virtual int do_look(CChar * me)
{
	if(me->query("xy/renwu8_1") )
	{
		say("ֻ���������ݺύ�����������Ľ��˻�����һ���������֡��������ĵ����ˣ�����ͻ����������б�ᣬ˵�����ĳ���ѿ���", me);
		SendMenu(me);
		return 1;
	}
	
	return CChar::do_look(me);
}

int do_talk(CChar * me, char * ask = NULL)
{
	if((EQUALSTR((me->environment())->querystr("base_name"), "��ң��С��" )))
	{
		if(me->query("xy/renwu4_3") && ! me->query("xy/renwu4_61"))
		{
			if(! strlen(ask))
			{
				AddMenuItem("���빲ͬ�ᱦ","duobao",me);
				SendMenu(me);
			}
			else if(!strcmp(ask, "duobao") )
			{
				say("���������˵������������ǰ���������ᱦ����������ǳ�����������ܼ�����֪ʦ��ɷ���������",me);
				if((!me->query("xy/renwu4_4") ||me->query("xy/renwu4_4")==2 ) &&!me->query_temp("xy/renwu4_1"))
				{
					say("�����˵�������ðɣ��ұ�����ȥһ�ˣ���",me);
					tell_object(me,"$HIC����۾�����ʼ�������ж���");
					set_leader(me);
					set("owner",atoi(me->id(1)));
					me->set_temp("xy/renwu4_1",2);//��������۳ɹ�1����ɽ���� 2�������
					if(!me->query("xy/renwu4_4"))
						me->set("xy/renwu4_4",2);	//���������ǰȥ�ᱦ��1����ɽ���� 2�������
				}
				else if(me->query_temp("xy/renwu4_1"))
				{
					say("�����������üͷ��",me);
				}
				else
				{
					say("�����˵������ʦ�㱾����ô���������㣬�ǻ���������ʲôѽ����",me);
				}
				SendMenu(me);
			}
			return 1;
		}
	}
	return CNpc::do_talk(me,ask);
}

virtual char * chat_msg()
{
	if(query("owner"))
	{
		char msg[255];
		CUser * me;
		snprintf(msg,255,"%d",query("owner"));
		me=find_online(msg);
		if(!me)
		{
			destruct(this);
		}
		else if(me->query("xy/renwu4_4")==2 && me->query_temp("xy/renwu4_1")==2)
		{
			
			if(me->query_temp("fight/is_fighting") 
				&& EQUALSTR(((me->environment())->environment())->name(1),(environment())->name(1)))
			{
				int team;
				CFightRoom * obj=(CFightRoom *)me->environment();
				if(me->query_temp("fight/fight_team"))		//����A��
					team = 1;
				else
					team = 0;
				move(obj);
				obj->Join_Team(this, team);
			}
		}
		else
		{
			destruct(this);
		}
	}
	return 0;
}

virtual void die()
{
	if(query("owner"))
	{
		char msg[255];
		CUser * me;
		snprintf(msg,255,"%d",query("owner"));
		me=find_online(msg);
		if(me)
		{
			if(me->query("xy/renwu4_4")==2 && me->query_temp("xy/renwu4_1")==2)
			{
				me->delete_temp("xy/renwu4_1");
			}
		}
	}
	CNpc::die();
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "����������") && EQUALSTR(ob->querystr("base_name"), "qinglong_pao") 
		&& me->query("xy/renwu4_61") && !me->query("xy/renwu4_63") && me->query("xy/renwu4_4")==2
		&&!me->query("xy/renwu5"))
	{
		if(EQUALSTR(me->querystr("family/family_name"), "��ң��"))
		{
			tell_object(me,"\n$HIR�����˫������½󣬷�������һ�΢Ц��˵������ʦֶ�����ˣ��������Ϊ����������һʽ�����ưɣ���");
			tell_object(me,"\n$HIR������������۽��⡰�����ơ��ľ�Ҫ���ڣ��ԡ������ơ����˸���һ��ε���⡣");
			switch(random(3))
			{
			case 0:
				me->add("skill_pro/���չ�/������/force",1);
				tell_object(me,"$HIR�������������ڹ������ڻ��ͨ�ˡ�\n");
				break;
			case 1:
				me->add("skill_pro/���չ�/������/dodge",1);
				tell_object(me,"$HIR���������ʹ�õø��ӵ���Ӧ���ˡ�\n");
				break;
			case 2:
				me->add("skill_pro/���չ�/������/damage",1);
				tell_object(me,"$HIR������������������ˡ�\n");
				break;
			}
		}
		else
		{
			tell_object(me,"\n$HIR�����˫������½󣬷�������һ�΢Ц��˵������ʦֶ�����ˣ��������Ϊ������ָ���㼸ʽ�书�ɣ���");
			tell_object(me,"������������۵Ľ��⣬����ѧ�������˸���һ��ε����,����������1000��ľ��顣��");
			me->add("combat_exp",1000);
			me->UpdateMe();
		}
		me->set("xy/renwu4_63",1);//�����������͸������
		me->set("xy/renwu5",1);//��ң����������岿�֣�������ߧ����
		destruct(ob);
		return 1;
	}

	return 0;
}

NPC_END;




