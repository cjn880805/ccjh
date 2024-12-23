//lanwood 
//	�����ҵ�����ɱ����
//	ԭ����MM
//	�޸ģ�Lanwood
//	���ڣ�2001-04-12
//	���ӷ�Χ��ȫ����NPC��ֻҪ��NPC�����п��ܱ�ͨ����
//	���������Ѷȣ�ͨ��NPC��ǿ������ҵ�2����ʹ����������ֵļ��ܡ�
//	���Լ�ʹ�ÿ��õ�PERFORM
//	��������ҵ�1��2 ~ 2 �������ܵȼ�����ҵ�1��2 ~ 2��  
//  1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0  ͨ��9�ֲ�ͬ�Ĺ���

//	ʹ��������̬���ɣ���owner���ԡ�damageΪ��ҵ�damage��
//	������ҵ�apply���attack��dodge��defense��armor��parry��
//	������100�����£��������顣exp = (level * 65 ~ level * 130)
//		  100�����ϣ���ѧϰ������ܡ������顣���ûѧ�ɣ��������飺(level * 60 ~ level * 120) * �Ѷ�ϵ��

CNpc * random_npc();

NPC_BEGIN(CNwanjie_foolmaster);

void create()
{
		set_name("��������","jieyugu zhuren");

        set("long", "������ٹȵ����ˣ��ԺŽ������ˡ�\n");
        set("title", "��ٹ���");
        set("gender", "����");
        set("age", 53);

        set("attitude", "peaceful");
	 	set("icon",old_man1);

        set("per", 1);
        set("str", 500);
        set("hp", 500000);
        set("max_hp", 500000);

        set("combat_exp", 20000000);
        set_skill("unarmed", 800);
		set("no_talk",1);
		set("task_open", 1);	//���񿪷�
/*
		//���
		room_decode.set("����", "����ɽһ��");
		room_decode.set("����", "��������");
		room_decode.set("����", "����һ��");
		room_decode.set("�ɶ�", "�ɶ�����");
		room_decode.set("����", "����һ��");
		room_decode.set("����", "���Ҹ���");
		room_decode.set("��ɽ", "��ɽ����");
		room_decode.set("����", "����ĳ��");
		room_decode.set("����", "����һ��");
		room_decode.set("����", "����ɽׯ");
		room_decode.set("��Ĺ", "����һ��");
		room_decode.set("����", "���ݸ���");
		room_decode.set("��ľ", "��ľ�¸���");
		room_decode.set("��ɽ", "��ɽ����");
		room_decode.set("��ɽ", "��ɽ����");
		room_decode.set("����", "����һ��");
		room_decode.set("�ƺ�", "�ƺ�һ��");
		room_decode.set("��ɽ", "��ɽ����");
		room_decode.set("����", "���ݸ���");
		room_decode.set("����", "��ɽһ��");
		room_decode.set("����", "����ĳ��");
		room_decode.set("÷ׯ", "÷ׯһ��");
		room_decode.set("����", "��������");
		room_decode.set("����", "���ݸ���");
		room_decode.set("���", "�ɶ�����");
		room_decode.set("Ȫ��", "Ȫ�ݸ���");
		room_decode.set("����", "��ɽһ��");
		room_decode.set("����", "�䵱����");
		room_decode.set("��ɽ", "��ɽһ��");
		room_decode.set("����", "���ݸ���");
		room_decode.set("̩ɽ", "̩ɽɽ��");
		room_decode.set("̨��", "̨��һ��");
		room_decode.set("�һ�", "�һ�ɽׯ");
		room_decode.set("����", "������");
		room_decode.set("���", "���Ҹ���");
		room_decode.set("�䵱", "�䵱����");
		room_decode.set("�书", "����һ��");
		room_decode.set("����", "��ɽ����");
		room_decode.set("����", "��������");
		room_decode.set("��ң", "��������");
		room_decode.set("����", "��ɽһ��");
		room_decode.set("����", "����һ��");
		room_decode.set("Ѫ��", "Ѫ��һ��");
		room_decode.set("ѩɽ", "ѩɽ����");
		room_decode.set("����", "���ݸ���");
		room_decode.set("����", "�����븽��");
		room_decode.set("����", "����һ��");
		room_decode.set("����", "����һ��");
		room_decode.set("����", "��������");
*/
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

	if(! who) return;

    message_vision("$n�����ɨ��$Nһ�ۡ�", who, me);

	return;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(query("task_open"))
	{
		AddMenuItem("���ɴ�˵", "$0getinfo $1", me);
		AddMenuItem("ն����ħ", "$0askquest $1", me);
		AddMenuItem("�ɹ�����", "$0report $1", me);
		AddMenuItem("����ʧ��", "$0fail $1", me);
		SendMenu(me);	
		return 1;
	}
	else
	{
		say("����̫ƽ�����¿�����", me);
		SendMenu(me);
	}

	return CNpc::do_talk(me, ask);
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(query("task_open"))
	{
		if(strcmp(comm, "getinfo") == 0)
			return do_gi(me);
		if(strcmp(comm, "askquest") == 0)
			return do_aq(me);			
		if(strcmp(comm, "report") == 0)
			return do_r(me);
		if(strcmp(comm, "fail") == 0)
			return do_f(me);
	}

	return CNpc::handle_action(comm, me, arg);
}

int do_gi(CChar * me)
{
		say("�������˿���������", me);
		say("�������˵����ݺ���꣬ħ�����������´��ң�ħ��Ӻڰ����߳�������ͼռ���أ��������ΪһԪ��а��", me);
		say("�������˵����Σ����ɹţ������壬��������������ڱ��������������ĵ��⣬��ʱ�ĺ�ƽ��������ͬ�Ը��п�ĵ��ˡ� ", me);
		say("�������˵���ħ��������ս���ڵ� 17 �꣬�Ѿ���Ҫ����β����ħ�����ڱ�ȫ�����˵�̩ɽ���ϣ�ħ����ħ��������һ����磬��̩ɽ��ס�����������ȥ����ս���е�Ӣ�۵�����ٻ���������ЩӢ���ǵ���걻ħ�����ƣ�ʧȥ�˱��ԣ���̩ɽ�����ε���ֻҪ�����˾ͻṥ����һʱ���������������ڵ�̩ɽ��Ȼ��Ϊ��һ������֮ɽ�� ", me);
		say("�������˵���Ҳ�������ʱ���������ͻȻ����ƽ�ֺ�ɽΪ������ħ��ǩ�º��飬һֱ���ı���ʵ����������������Ӫ����һ������ռ���˹��⣬ʱ����ԭɧ�ţ�һ���ǵõ��ڰ������������������ţ�һ�������Ĳ�����ħ�塣����ľ��Ӵ�������л�֮�С�һʱ������ҡ� ", me);
		say("�������˵������ǣ��������������ʵ���Ĳ�������Щ���ҵľ������������ǡ���������һ�������������Ӣ�ۡ� ", me);
		say("�������˵���������˼�ǡ����ˡ����˽������������ǲ���һ�������Խ�Ϊ�������������Ѿ���Ϊ�����ǵ�ͳ�ơ� ", me);
		say("�������˵�����Щ���������Ƕ�Ӣ����ս�����ǰ���ս�������Ĳ�ͬ����Ϊ�ܶ�������ɡ���ÿ�����ɶ������ǵĶ���֮������Щ�����������ķ������ڲ��ϵ�ս���ж����Լ�������ΪĿ�ꡣ", me);
		say("�������˵������죬��վ���ҵ���ǰ����֪����ض�Ҳ�ǡ���������һԱ��", me);
		say("�������˵���ȴ��֪�����Ƿ�Ը��Ϊն����ħ��һ���ౡ֮����ͬʱ���Լ�������", me);
		SendMenu(me);
		return 1;
}

//����npc�ķ�λ
const char * position_npc(CChar * npc)
{
	CContainer * env = npc->environment();
	if(! env) return 0;	//ʧ��
	if(env->query("no_fight")) return 0;	//��ս������
	if(env->query("wiz_room")) return 0;	//��ʦ���䡣
	if(env->query("sleep_room")) return 0;	//��Ϣ����
	if(EQUALSTR(env->querystr("area"), "house")) return 0;	//���סլ
	if(EQUALSTR(env->querystr("id"), "fight_room")) return 0;	//ս������
	if(atoi(env->querystr("owner"))) return 0;	//���סլ

	while(env->environment())
		env = env->environment();

	//return room_decode.querystr(env->querystr("area"));
	return env->name(1);
}

int do_aq(CChar * me)
{
	char msg[255];

		static struct {
		char name[40];
		char desc[80];
	}monster[9] = {
		{"С��", "Ƿ����С��һƿ��Ǯ"},
		{"ؤ�����", "����ˣ����ƭ��Ǯ��"},
		{"��������", "ǿ��ǿ�������а���"},
		{"������", "͵����������ѹ����"},
		{"�˷���", "������Ů��������"},
		{"���Ŷ���", "��ҽ��ᣬ���а�Ů"},
		{"���̵���", "ɢ��а�̣��ƻ�����"},
		{"��͢����", "ͨ���������к�����"},
		{"���ɱ��", "����PK����������"},	
	};

		LONG monster_id;

		if (me->query("combat_exp") < 10000)
			return notify_fail("�������˵��������ˣ������������»�������Ϊ�á���");
		
		if (me->query_temp("fool/finish"))
			return notify_fail("�������˵��������������Ϊ�β����Ϸ�Ҫ��ر���");
		
		if ( (monster_id = me->query_temp("fool/doing")) )
		{
			//�ж������Ƿ�ʧ��
			CChar * mon = find_npc(monster_id);
			if(! mon)
				return notify_fail("��������ŭ�����������������£��Ѿ���ʧ��������");

			const char * area = position_npc(mon);
			if(! area) return notify_fail("��������ŭ�����������������£��Ѿ���ʧ��������");

			int diff = me->query_temp("fool/diff");
			tell_object(me, snprintf(msg, 255, "$HIW�������˵�����%s��%s%s��\n�Ҳ���������ȥ�����������°������𡣻�����ȥ��", monster[diff].name, area, monster[diff].desc));
			return 1;
		}
		else if(me->query("foolmaster"))	//����ʧ
		{
			return notify_fail("��������ŭ�����������������£��Ѿ���ʧ��������");
		}
		
		if (me->is_busy())
			return notify_fail("�����ں�æ������");
	
	//�����һ��NPC�ĺ���

	CNpc * npc = random_npc();

	if(! npc) return notify_fail("��Ȼû��NPC�ˡ�");
	if(npc == this) return notify_fail("�������˲��ͷ��ĵ�����һ�������ɡ�");	//�Լ���Ȼ�������֡��Ǻǡ�
	if(! living(npc)) return notify_fail("�������˲��ͷ��ĵ�����һ�������ɡ�");	//���NPC�첻���ˡ�
	if(DIFFERSTR(npc->querystr("race"), "����") ) return notify_fail("�������˲��ͷ��ĵ�����һ�������ɡ�");	//������NPC
	if(npc->query("monster_lvl")) return notify_fail("�������˲��ͷ��ĵ�����һ�������ɡ�");	//��̩ɽ���������
	if(npc->query("no_kill")) return notify_fail("�������˲��ͷ��ĵ�����һ�������ɡ�");	//��һ����Ҳ������ҵ����������
	if(npc->query("mfnpc_lvl")) return notify_fail("�������˲��ͷ��ĵ�����һ�������ɡ�");	//������ɽ���������
	
	CContainer * env = npc->environment();

	//�����ж�NPC���µķ�λ
	const char * area = position_npc(npc);
	if(! area ) return notify_fail("�������˲��ͷ��ĵ�����һ�������ɡ�");	//���NPCû�л���
	if(! area[0]) return notify_fail("�������˲��ͷ��ĵ�����һ�������ɡ�");	//���NPC����ҷ������ս���С�
		
	int diff = random(9);
	
	//����ҽ�����
	load_item("jieyuling")->move(me);

	me->set_temp("fool/doing", npc->object_id());	//�ҵ���NPC��
	me->set_temp("fool/diff", diff);			//�Ѷ�ϵ��
	me->set_temp("fool/name", monster[diff].name);	//
	me->set_temp("fool/where", area);

	me->set("foolmaster", 1);	//�ӹ������ˡ�
		
	message_vision(snprintf(msg, 255, "$HIW�������˶�%s˵������%s��%s%s��\n����ȥ�����������°��ա�", me->name(), monster[diff].name, area, monster[diff].desc), me);

	g_Channel.do_channel(&g_Channel, NULL, "sys", 
		snprintf(msg, 255, "%s��ɱ%s��%s������", me->name(1), env->querystr("base_name"), npc->name(1)));
		
	return 1;

}

int do_f(CChar * me)
{
//		if (me->query("teapot/fool_finish"))
//			return notify_fail("�������˵��������������Ϊ�λ�Ҫ������");
		
		if(! me->query("foolmaster"))
			return notify_fail("�������˺ȵ����������Ӧ�Ϸ�ȥն����ħ��ĪҪ���֣�");

		CContainer * obj;
		
		if ( (obj=me->present("jieyu ling"))  )
			destruct(obj);
			
		message_vision("$HIY��������ŭ����ȣ�$N����˲��������Ϸ���ζԵ�������������", me);
		message_vision("$HIY��ͻ�Ž���������˴�ȣ����ϲ������������ǰ������ð��վ�����ȣ�", me);
		
		me->receive_wound("hp", me->query("max_hp") / 3, this);
		me->receive_damage("hp", me->query("max_hp") / 2, this);
		me->SendState(me);

		if(! random(10))
			me->unconcious();
		else
			me->start_busy(30);

		me->delete_temp("fool");
		if(me->query("fool1/count")>10)
			me->add_temp("fool1/count",-10);
		else
			me->delete_temp("fool1/count");
		me->del("foolmaster");
	
		return 1;
}

//������
void reward_exp(CChar * me)
{
	char msg[255], tmp[20];
	LONG exp = me->query("level");		

	exp = 100+exp * 3;
	
	//exp = exp * (10 + me->query_temp("fool/diff")) / 10;	//�Ѷ�ϵ��
	exp = exp + random(me->query_temp("fool/diff") * me->query("level")/10);	//�Ѷ�ϵ��

	exp = (random(exp) + exp) / 2;
	exp=exp*(1+me->query_temp("fool1/count")/10);
	me->add_temp("fool1/count",1);
	if(me->query_temp("fool1/count")>30)me->set_temp("fool1/count",1);

	me->add("combat_exp", exp);
	int repute=int((random(31)+100)*(10+me->query_temp("fool1/count"))/10);
	me->add("repute",repute);
	tell_object(me, snprintf(msg, 255, "$HIC������%s�㾭�顢%d�㽭��������", chinese_number(exp, tmp),repute));

	g_Channel.do_channel(&g_Channel, 0, "sys", 
		snprintf(msg, 255, "%s�������%sɱ%s�����񣬻��%d���顢%d�㽭��������", me->name(1), me->querystr_temp("fool/where"),me->querystr_temp("fool/name"),  exp,repute));

	me->FlushMyInfo();
}

//���������һ������
int learn_skill(CChar * me, const char * myskill)
{
	char msg[255];
	CSkill * sk = load_skill(myskill);

	if( !sk->valid_learn(me) ) return 0;

	//��ҵļ��ܾ������ܾ����еı��ز��ܳ���1/3
	if(me->query("sk_exp") * 3 > me->query("combat_exp"))
		return 0;
				
	//���ڼ�������ľ���
	LONG need_points =  me->skill_need_points(myskill);
	LONG need_exp = need_points / me->learn_bonus() + 1;
		
	//������ҵľ��鹻����
	if(me->query_valid_exp() < need_exp)
		return 0;
	    
	//������ҵļ��������з�ﵽ
	if( strcmp(sk->type(), "martial") == 0 &&
		me->query_skill(myskill, 1) >= CChar::level2skill(me->query("level")) ) 
		return 0;
	
	me->add("sk_exp", need_exp);
	me->improve_skill(myskill, need_points + 1);
	
	me->FlushMyInfo();

	tell_object(me, snprintf(msg, 255, "$HIC%s������һ��%s��", name(), sk->name(1)));
	g_Channel.do_channel(&g_Channel, 0, "sys", 
		snprintf(msg, 255, "%s�������%sɱ%s�����񣬻��%s����һ����", me->name(1), me->querystr_temp("fool/where"),me->querystr_temp("fool/name"),  sk->name(1)));

	return 1;	
}

/*
//������
int reward_skill(CChar * me)
{
	CMapping * skills = me->query_skills();
	int count = skills->GetCount();
	if(! count) return 0;

	count = random(count);

	CVector v;
	skills->keys(v);
	return learn_skill(me, v[count]);
}
*/

int do_r(CChar * me)
{
	if (!me->query_temp("fool/finish"))
		return notify_fail("�������˵�������δ������񣬲�Ҫ���֣�");
		
	CContainer * obj;
		
	if (!(obj=me->present("jieyu ling"))  )
		return notify_fail("������������ĵ����Ҹ���������أ�");
		
	message_vision("$HIG�������˵����ã��ã�$N���Ϸ��Ȼû�����ˣ�",me);
	
	reward_exp(me);
	
	destruct(obj);
	me->delete_temp("fool");
	me->del("foolmaster");
	me->start_busy(6);

	return 1;
}

protected:
	CMapping		room_decode;

NPC_END;

//��ٹ�ʯ��



