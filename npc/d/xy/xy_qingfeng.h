//xy_qingfeng.h

NPC_BEGIN(CNxy_qingfeng);

virtual void create()
{
	set_name("���", "qing feng");
	set("long","������ȥ����������ģ��Ҳ�������ʣ�����վ���ļ�ʽ���֪��һ����Ϊ���ǲ��ס�");
	set("gender", "����");
	set("age", 16);
	set("attitude", "peaceful");
	set("foolid",126);
	set("shen_type", 1);
    set("class", "taoist");
	set("icon",boy2);	
	
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("per", 28);
	set("icon",taoist);	
	
	set("hp",20000);
	set("max_hp", 20000);
	set("mp", 12000);
	set("max_mp", 12000);
	set("mp_force", 100);
	set("combat_exp", 3000000);
	set("score", 100000);
	
	set_skill("force", 200);
	set_skill("taiji_shengong", 200);
	set_skill("dodge", 200);
	set_skill("tiyunzong", 200);
	set_skill("unarmed", 200);
	set_skill("taiji_quan", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji_jian", 200);
	set_skill("taoism", 200);
	set_skill("literate", 200);
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	
	create_family("�䵱��", 4, "����");
	set("class", "taoist");
	
	set("chat_chance_combat", 60);
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
	
	set("apply/armor", 150);
    set("apply/damage", 100);
	set("no_chan",1);
	set("shen_type", 1);
	set("no_kill",1);
	
}

virtual char * chat_msg_combat(CChar * player)
{
	switch(random(4))
	{
	case 0:
		perform_action("sword lian", 1);
		break;
	case 1:
		perform_action("sword lian", 1);
		break;
	case 2:
		perform_action("sword sui", 1);
		break;
	case 3:
		perform_action("force recover",0);
		break;
	}
	
	return 0;
}

int handle_action(char * comm, CChar * me, char * arg)
{
	if(strcmp(comm, "fight") == 0 && me->query("xy/renwu5_2") && !me->query("xy/renwu5_3") 
		&& EQUALSTR(environment()->querystr("base_name"),"��ң��׷�¹ۻ���ͥ" ))
		return do_fight(me);
	
	return CNpc::handle_action(comm, me, arg);
}

int do_fight(CChar * me)
{
	set("hp", query("max_hp"));
	set("eff_hp", query("max_hp"));
	set("mp", query("max_mp"));
	
	me->set_temp("fight_ok", 1);
	Do_BiShi(this, me, "����ս��", 20);
	return 1;
}

//���Խ���
void is_defeated(CChar * winner, CChar * failer)
{
	CChar * me = failer;
	if(failer == this)	//��ʤ,���ñ��.�ӳٺ���,�Ա��ս��������.
	{
		if(! winner->query_temp("fight_ok")) return;
		winner->delete_temp("fight_ok");
		winner->set_temp("xy/renwu5_5", 1);//�����ʤ
		me = winner;
	}
	
	remove_call_out(do_join);
	call_out(do_join, 2, me->object_id(), 30);
}

static void do_join(CContainer * ob, LONG param1, LONG step)
{
	CChar * npc = (CChar *)ob;
	CChar * me = (CChar *)(npc->environment())->Present(param1);
	
	if(! me) 
	{
		if(step > 0) npc->call_out(do_join, 2, param1, step - 1);
		return;
	}
	
	if(me->query("xy/renwu5_2") && me->query_temp("xy/renwu5_5"))	//��ʤ�Ļ�
	{
		CContainer * weapon;
		if( EQUALSTR(me->query_skill_mapped("sword"), "xiaoyao_jianfa") 
					&& ((weapon = me->query_weapon())&& EQUALSTR(weapon->querystr("skill_type"), "sword")))
		{
			tell_object(me,"\n$HIY������������ض�˾������˵������ʦ�����Բ����Ҵ�Ӯ������");
			tell_object(me,"$HIY˾�����鳤̾��һ������˵��������������������ߧ������Ե����");
			tell_object(me,"$HIY˾�����鱧ȭ����ң��˵��������ϲ��ң�͵ܣ��Ժ���ߧ���ص����˾������ˣ���");
			
			tell_object(me,"\n$HIY��ң��æ�����������֣�����⸣����ʱ��ӭ����٣���ʵ������������һֱ���룬�����������Լ���Ǻοࣿ��");
			tell_object(me,"$HIY��ң��̾�����������̶���ʮ�أ����ⶴ�У������ֻ��ǧ��������һ��֮����ѧ�����е���ܸ����ѧ��֮��������Σ���");
			tell_object(me,"$HIY��ң��̾��������������û��һ��֪����ͬ����̽���Ŀ��֣����к��⣿��");
			
			tell_object(me,"\n$HIY˾������ҡ��ҡͷ���������Ŷ��������Ҽ�������ⳡ���ԣ��Ե�����������˳�����Щ���ӣ���ҲҪ�뿪�˵��ˣ���ң�͵ܣ��Ժ�������ء���ǣ���");
			tell_object(me,"$HIY��ң��˫�ֱ�ȭ���������С�����и����ˣ�������������أ���");
			
			tell_object(me,"\n$HIY˾�������ֻ�ͷ����˵��������λС�����п��У��뵽����С��Ƭ�̣���");
			me->set("xy/renwu5_3",1);//�����ʤ�������ߧ����
		}
		else
		{
			tell_object(me,"\n$HIY˾���������һЦ������ң�͵ܣ��벻����ĸ�ͽ��˶�ţ���������Լ���õı��Ž���Ҳ���������ȡʤ����");
			tell_object(me,"$HIY˵�գ�ת����䣬��Ц��������磬�����ߣ���");
			
			tell_object(me,"\n$HIR�������˲����������꣬��ң�ӡ��ߡ���һ����ת��Ҳ���˳�ȥ��");
			tell_object(me,"$HIR�㲻��һ��֣̿��ƺ������Լ��������õ��书�������ס�");
			me->delete_temp("xy");
			me->del("xy/renwu5_2");
		}
		
		CContainer * Xy_Npc;
		CContainer * env=me->environment();
		Xy_Npc=env->present("xiaoyao zi");
		if(Xy_Npc)
		{
			tell_object(me,"\n$HIW��ң����׷�¹۴����뿪��");
			destruct(Xy_Npc);
		}
		Xy_Npc=env->present("li qiou heng");
		if(Xy_Npc)
		{
			tell_object(me,"$HIW�������׷�¹۴����뿪��");
			destruct(Xy_Npc);
		}
		Xy_Npc=env->present("li cang hai");
		if(Xy_Npc)
		{
			tell_object(me,"$HIW��׺���׷�¹۴����뿪��");
			destruct(Xy_Npc);
		}
		
		Xy_Npc=env->present("shikong zixu");
		if(Xy_Npc)
		{
			tell_object(me,"\n$HIW˾��������׷�¹۾�˼ͥ�뿪��");
			destruct(Xy_Npc);
		}
		Xy_Npc=env->present("qing feng");
		if(Xy_Npc)
		{
			tell_object(me,"$HIW�����׷�¹����䳡�뿪��");
			destruct(Xy_Npc);
		}
		
	}
	else//ʧ�ܵĻ�����������
	{
		if(me->query_skill("xiaoyao_jianfa",1))
		{
			me->delete_skill("xiaoyao_jianfa");
			me->FlushMySkill(me);
		}
		me->del("xy");
		me->delete_temp("xy");
		
		CContainer * yinyue_si;
		yinyue_si=me->present("yingyue si");
		if(yinyue_si)
			destruct(yinyue_si);
		
		tell_object(me,"\n$HIR��ͻȻ����ͷ�����ѣ��к��䣬�����Լ���ɵɵ��վ����ң��ʯ�ݣ��ƺ�ʲô��Ҳû�з�����");
		me->move(load_room("��ң��ʯ��"));
	}
}

NPC_END;