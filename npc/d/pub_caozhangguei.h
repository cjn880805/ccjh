//���ƹ�(�����Ͳ�����NPC)
//�ز� 2003��5��23

CNpc * random_npc();

NPC_BEGIN(CNpub_caozhangguei);

void create()
{
	set_name("���ƹ�","cao zhangguei");

	set("icon", pub_boss);
	set("gender", "����" );
	set("title", "��¥�ϰ�" );
	set("age", 42);
	set("long","��������¥��¥�Ĵ��ƹ񣬿������Ͱ����ס�");
	set("combat_exp", 100);
	set("nkgain", 30);

	set("attitude", "friendly");
	set("no_get", "1");

	set("task_open", 1);	//���񿪷�
	set("no_kill",1);
	set("no_huan",1);
	
};

void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 3, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	char msg[255];
	if(! who) return;
    if(who->query("combat_exp")>50000 || me->query("level")>30) return;
	if(who->query_temp("cao/overtime")) return;

	tell_object(who,"\n���ƹ����潹�ǣ�̾�������������Ļ���ֽ�̫������ô��Ŀ͹ٶ��ķ��ˣ�����ô���ü���ѽ����");
	tell_object(who, snprintf(msg, 255,"���ƹ�һ������������ϲ������˵��������λ%s,��֪�Ƿ�����Ȥ������������Щ�͹ٶ��ķ��ˣ���\n", query_respect(me)));
		

	return;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(query("task_open"))
	{
		if(me->query("combat_exp")<50000 && me->query("level")<30)
		{
			me->set_temp("cao/����", 1);
			if(!me->query_temp("cao/overtime"))
				AddMenuItem("����ƹ���Ҫ����", "$0getquest $1", me);
			else
			{
				AddMenuItem("����ƹ�ѯ������", "$0askquest $1", me);
				AddMenuItem("����ƹ�Ҫ���������", "$0cleanquest $1", me);
			}
			SendMenu(me);	
		}
		else
			return CNpc::do_talk(me,ask);
	}
	else
		return CNpc::do_talk(me,ask);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg)
{
	if(me->query_temp("cao/����"))
	{
		me->delete_temp("cao/����");
		if(strcmp(comm, "askquest") == 0)
			return do_aq(me);
		if(strcmp(comm, "getquest") == 0)
			return do_gq(me);
		if(strcmp(comm, "cleanquest") == 0)
			return do_cq(me);
	}
	return CNpc::handle_action(comm, me, arg);
}


int do_aq(CChar * me)
{
	char msg[255];
	if(!me->query_temp("cao/overtime"))
	{
	    say("���ƹ����潹�ǣ�̾�������������Ļ���ֽ�̫������ô��Ŀ͹ٶ��ķ��ˣ�����ô���ü���ѽ����", me);
		say(snprintf(msg, 255,"���ƹ�һ������������ϲ������˵��������λ%s,��֪�Ƿ�����Ȥ������������Щ��������",query_respect(me)), me);
		SendMenu(me);
		return 1;
	}
	long i;
	long e;
	
	i=current_time;
	e=me->query_temp("cao/overtime");
	if (i>e)
	{
	    tell_object(me,"���ƹ�����һ�ų����������㡰�ߡ���һ����");
		say("�Բ��𡭡�ʱ���Ѿ����ˣ���û���������", me);
		SendMenu(me);
		return 1;
	}
	i=e-i;
	e=i/60;
	i=i-e*60;

    say("���ƹ�΢΢��Щ���죬����üͷ˵����������������ˣ���ô������˲��á���", me);
	say(snprintf(msg, 255, "���ƹ�˵������%s(%s)�Ѿ���%s���˺ܾ��ˣ��㻹�������ȥ��Ҫ���ٹ�%d��%d�뻹��û���Ļ����͹�һ���ᷢŭ�ġ���", 
		me->querystr_temp("cao/name"),me->querystr_temp("cao/id"), me->querystr_temp("cao/map"),e,i), me);
	SendMenu(me);
	return 1;
}


int do_cq(CChar * me)
{
	char msg[255];
	if(!me->query_temp("cao/overtime"))
	{
		say(snprintf(msg, 255,"���ƹ����澪�ȵ�˵��������λ%s,�˻��Ӻ�˵�𣿡�",query_respect(me)), me);
		SendMenu(me);
		return 1;
	}
	say("���ƹ��������죬˵�������������ŵģ���ô���µġ��ȱ�˵��ģ��ղ���λ�͹ٶ��ķ����ܹ�500�ģ�����������˵����", me);
	SendMenu(me);
	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (EQUALSTR(ob->querystr("id"), "coin") && ob->query("value")==500)
	{
		who->delete_temp("cao/id");
		who->delete_temp("cao/name");
		who->delete_temp("cao/map");
		who->delete_temp("cao/overtime");
		who->delete_temp("cao/count");	// Clear Finish 	
		destruct(ob);
		return 1;
	}
	return 0;
}

//����npc�ķ�λ
const char * position_npc(CChar * npc)
{
	CContainer * env = npc->environment();
	if(! env) return 0;	//ʧ��
	if(env->query("no_fight")) return 0;	//��ս������
	if(env->query("wiz_room")) return 0;	//��ʦ���䡣
	if(env->query("renwu")) return 0;		//�������񷿼䡣
	if(env->query("sleep_room")) return 0;	//��Ϣ����
	if(EQUALSTR(env->querystr("area"), "house")) return 0;	//���סլ
	if(EQUALSTR(env->querystr("area"), "Ұ��")) return 0;	//Ұ�ⳡ��
	if(EQUALSTR(env->querystr("id"), "fight_room")) return 0;	//ս������
	if(atoi(env->querystr("owner"))) return 0;	//���סլ

	while(env->environment())
		env = env->environment();

	return env->name(1);
}

int do_gq(CChar * me)
{
	char msg[255];
	long i;
	long e;
	i=current_time;
	e=me->query_temp("cao/overtime");
	if(me->query_temp("cao/overtime"))
	{
		say("����һ������û����ɡ���", me);
		SendMenu(me);
	}
	
	if (me->query("combat_exp") > 10000)
		return notify_fail("���ƹ������Ц������λ�͹٣����ⲻ������ǲ�������������������Щ����ѽ��");
	
	if (me->is_busy())
		return notify_fail("�����ں�æ������");

	//���ȡһ��NPC�ĳ���	
	CNpc * npc = random_npc();

	if(! npc) return notify_fail("���ƹ�̾������������֪Ϊ�Σ��������һֱ���ã�ûʲô�͹�Ը�������ˣ�");
	if(npc == this) return notify_fail("���ƹ�̾������������֪Ϊ�Σ��������һֱ���ã�ûʲô�͹�Ը�������ˣ�");	//�Լ���Ȼ�������֡��Ǻǡ�
	if(! living(npc)) return notify_fail("���ƹ�̾������������֪Ϊ�Σ��������һֱ���ã�ûʲô�͹�Ը�������ˣ�");	//���NPC�첻���ˡ�
	if(DIFFERSTR(npc->querystr("race"), "����") ) return notify_fail("���ƹ�̾������������֪Ϊ�Σ��������һֱ���ã�ûʲô�͹�Ը�������ˣ�");	//������NPC
	if(npc->query("no_kill")) return notify_fail("���ƹ�̾������������֪Ϊ�Σ��������һֱ���ã�ûʲô�͹�Ը�������ˣ�");	//��һ����Ҳ������ҵ����������
	if(npc->query("mfnpc_lvl")) return notify_fail("���ƹ�̾������������֪Ϊ�Σ��������һֱ���ã�ûʲô�͹�Ը�������ˣ�");	//������ɽ���������
	
	CContainer * env = npc->environment();

	//�����ж�NPC���µķ�λ
	const char * area = position_npc(npc);
	if(! area ) return notify_fail("���ƹ�̾������������֪Ϊ�Σ��������һֱ���ã�ûʲô�͹�Ը�������ˣ�");	//���NPCû�л���
	if(! area[0]) return notify_fail("���ƹ�̾������������֪Ϊ�Σ��������һֱ���ã�ûʲô�͹�Ը�������ˣ�");	//���NPC����ҷ������ս���С�
	if(EQUALSTR(env->querystr("area"), "fight") ) return notify_fail("���ƹ�̾������������֪Ϊ�Σ��������һֱ���ã�ûʲô�͹�Ը�������ˣ�");	//���NPC����ҷ������ս���С�
	if(EQUALSTR(env->querystr("area"), "Ұ��") ) return notify_fail("���ƹ�̾������������֪Ϊ�Σ��������һֱ���ã�ûʲô�͹�Ը�������ˣ�");	//���NPC��Ұ�⡣
	if(env->query("renwu") ) return notify_fail("���ƹ�̾������������֪Ϊ�Σ��������һֱ���ã�ûʲô�͹�Ը�������ˣ�");	//���NPC����������ķ����С�
	
	me->set_temp("cao/id",npc->id(1));
	me->set_temp("cao/name",npc->name(1));
	me->set_temp("cao/map",env->name(1));
	
	say(snprintf(msg, 255, "���ƹ�˵����%s(%s)����ס��%s���������Թ�������һ����ϯ��˵�ý�����ȥ��", npc->name(1), npc->id(1),env->querystr("base_name")), me);
	int shuitime=300;
	i=400-me->query("level");
	i=i+shuitime;
	i=(i+random(i))/2;
	me->set_temp("cao/overtime",current_time+i);
	e=i/60;
	i=i-e*60;
	say(snprintf(msg, 255, "���ƹ�˵��������ʱ���Ѿ�����Ĳ���ˣ���Ͽ���%d��%d��֮�ڰ���Щ�˸����͹�ȥ�ɣ�", e,i), me);
	SendMenu(me);

	CContainer * ob=load_item("caiyao");
	ob->set("owner1",me->id(1));
	ob->set("cao/id",npc->id(1));
	ob->set("cao/name",npc->name(1));
	ob->set("cao/map",env->name(1));
	ob->move(me);

	me->set_temp("no_fei",1);
	me->set_temp("weight",me->Query_Weight());
	me->set_weight(5000000);
	return 1;
}

NPC_END;




