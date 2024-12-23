//lj_wulaoda.h	���ϴ�
//�ز� 2002��6��5

NPC_BEGIN(CNlj_wulaoda);

void create()
{
	set_name("���ϴ�","wulao da");
	set("long", "����Ȼ�书��̫�ߣ���ȷ�������ĺ��ӣ���Թ���������չ�������ʮ������������ʮ��������������Ϊ���졣");

	set("title", "���չ�����");
	set("gender", "����");
	set("age", 43);
	set("attitude", "peaceful");
	set("icon",young_man6);
	set("per", 10);
	set("str", 40);
	set("int", 25);
	set("con", 40);
	set("dex", 30);
	set("no_kill",1);
	set_weight(50000000);

	set("max_hp", 15000);
	set("mp", 8000);
	set("max_mp", 8000);
	set("mp_factor", 160);

	set("combat_exp", 800000);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hammer",100);
	set_skill("unarmed", 100);
	set_skill("yujiamu_quan", 100);
	set_skill("shenkong_xing",100);
	set_skill("xiaowuxiang", 100);
	set_skill("riyue_lun", 100);
  
	map_skill("force", "xiaowuxiang");
    map_skill("dodge", "shenkong_xing");
    map_skill("unarmed", "yujiamu_quan");
	map_skill("parry", "riyue_lun");
	map_skill("hammer", "riyue_lun");

	prepare_skill("unarmed", "yujiamu_quan");
	call_out(do_die, 1800);	
	set("no_kill",1);
};

void init(CChar * me)
{
	CNpc::init(me);
	if (me->query("lj/renwu6") ) 
	{
		CContainer * env = load_room("���괺�ó���");
		env->set("no_fight",1);
		env->set("no_move",1);
		me->set_temp("no_fei",1);
		tell_object(me, "\n$HIY�����ĵĽ����˼ó��ȣ����ֹ��оۼ��źܶ����ι�״���ˡ�");
		tell_object(me, "$HIY����һ�˿���������������ڶ�������˵�����������ƺ���������������˵���ټ��������ɴ������ϴ�");
		tell_object(me, "$HIY����ס������С������Ķ���һ������������̸����");
		call_out(do_taolun, 2);	
	}
	else if(!me->query("lj/renwu7")) 
	{
		tell_object(me, "\n$HIY�����ĵĽ����˼ó��ȣ����ֹ��оۼ��źܶ����ι�״���ˡ�");
		tell_object(me, "$HIY���ڴ�ʱ�����׸������и�����Ʈ�˹��������η����ˣ������ɴ�������ң����潫��ʮ������������ʮ�����������������������𣿡�");
		tell_object(me, "$HIY��Ȩ����һ�£���ס���棬��ͷ���˳�ȥ��");
		me->move(load_room("���괺������"));
	}
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env;
	env = load_room("���괺����");
	if(env->query("lj/wanxuanhuei"))
		tell_room(me->environment(), "\n$HIG���ɴ���Ѫ���ĺ󣬴��ɱ�����չ���ȡ��ҩȥѽ����\n");
	CContainer * env1=me->environment();
	if(env1->query("no_move"))
		env1->del("no_move");
	destruct(me);
}

static void do_taolun(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env=me->environment();
	switch(env->query("lj/taolun"))
	{
	case 0:
		tell_room(env, "\n$HIG���ϴ�˵�����������³�������������綴�������������յ����Ⱦ�����ֵ���");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 1:
		tell_room(env, "$HIG�ɰ������鱦������޳�С�ɽ�亣ζ����֬���۵���͵���ɽ��翷�ȥ����");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 2:
		tell_room(env, "$HIG�ҺͰ��������յ���������翷�֮ʱ���Ÿ������ﶼ���µ�Ҫ����");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 3:
		tell_room(env, "$HIG����������ǰ����Ҫ�뱸��ҩ�ʵ���м���̫���ѵã��������꺣��Ĺ군����߳���¹�ǣ�˵ʲôҲ�Ҳ�����");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 4:
		tell_room(env, "$HIG����δ����ȫ�����������ף�������һ���𷣱��ء�");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 5:
		tell_room(env, "$HIG��֪���Ÿ���սս�����Ľ�����Ʒ�����������˴���������");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 6:
		tell_room(env, "$HIG˵�������ɹ�����ƷҲ�����ˣ��Ÿ��������˵��������Ҽ���β�ͣ����·�ȥ�ա���");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 7:
		tell_room(env, "$HIG���Ǳ��������ʶ����⣬�����Ǵ�ϲ�����������·壬��������һ�̺�һ�̣���Ҫ�����ŷ�����Ʒ���ԣ�׷������������ɾ��ܵô��ˡ�");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 8:
		tell_room(env, "$HIG�Ÿ���������翷��£��������۵ĺڲ���ֻ��ɽ�������������ˡ�����һ����������ʶ�������Ĺ�һƷ���еĸ��֣����о�����ˡ�");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 9:
		tell_room(env, "$HIG�������������翷��£�����ȴ���������ˣ����پ�������Щ����ͷ��");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 10:
		tell_room(env, "$HIR\n�����������ϴ�˵�������ʱһƬ��Ȼ��\n ");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 11:
		tell_room(env, "$HIG���ϴ����˵������ɽͯ�Ѳ�ϲԶ�У����������ҵ���翷����֮��ȥ��Ұ�������Ǽ�����ʩչ�书��ʱ�� ");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 12:
		tell_room(env, "$HIG�������翷����֮�ڣ���Ҫɱ�ˣ����������Գ��֡� ");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 13:
		tell_room(env, "$HIG������֪����Ƣ������ʱ������һ�������ֵ���翷��£�������̫�Ź���ɱ�˵��ͷ�� ");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 14:
		tell_room(env, "$HIG��ɱ������һ�б㼴ȡ�������������ڶ���������������֮�� ");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;	
	case 15:
		tell_room(env, "$HIR\n�����������������ͷ��˼������������ɫ��\n ");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 16:
		tell_room(env, "$HIG���ϴ����˵������ʱ��һ��������������ˣ��������ɣ��ٿ������������ߣ��������������һ�������� ");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 17:
		tell_room(env, "$HIG�ҵ��±�Ͱ����յ���λ�ֵ����飬���¿�ʵ��͸�ŹŹ֡��ѵ�������˵����˲���ͯ����ɱ��");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 18:
		tell_room(env, "$HIG���粻��ͯ���µ��֣����չ���ͯ��������ЩŮ�ˣ���������������翷���ɱ�ˣ���ȥ��ͯ��һ��ɱ�˵���Ȥ��");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 19:
		tell_room(env, "$HIG���������Ⱥ��֣�ɱ���������������Ե���в����������Ǳ�֮��ȥͯ�ѵ��ڵ���ʳ����Ϊ������");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 20:
		tell_room(env, "$HIG���������������أ��߳�����󣬰�����ͻȻ˵������Ī����Ī���Ϸ��ˡ������ˡ������ˡ�������");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
	case 21:
		tell_room(env, "$HIR\n���˲�Լ��ͬ�Ķ����������˲�����\n");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 22:
		tell_room(env, "$HIG���ϴ������������漴�����˱�������ͯ���ѱ����ٸߣ��վ����������ɾ����н�ղ���֮��");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 23:
		tell_room(env, "$HIG��һ�����ǹ������Ʒ���룬�������𷣣����ǳ��棬��������˵����ڷ��£����Ͼ�Ȼ��ֹһ�ˣ�����������񼡣");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 24:
		tell_room(env, "$HIG�ܶ���֮������һ�����ش�Ź֡�");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
	case 25:
		tell_room(env, "$HIG��ʱ�������飬���ΰ���������̽�������������������岻�ݴǵ���Ըǰȥ�쿴��");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 26:
		tell_room(env, "$HIG���ϴ����˵������������翷��¿��Ⱥ򣬵����Ƕ������꣬���°�������ʲô���⡣");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 27:
		tell_room(env, "$HIGֱ��������ʱ�����������Żص�Լ�������֮�������Ǽ���������ϲɫ������ȷ�������ͷ��ʯ��");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 28:
		tell_room(env, "$HIG�������������Ϸ����в������ڷ��ϡ���");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 29:
		tell_room(env, "$HIGԭ���������ػ���翷壬���������ŵ���Ů��˵������֪���������ز��������ҩ��ҽȥ�ˣ�");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 30:
		tell_room(env, "$HIR\n���ϴ�˵�������Ⱥ�е�ʱ����һƬ����֮����\n��ɽͯ��������ѶϢ�����ǵ�Ȼ���ѵ�֪�����˾ۼ��ڴˣ�����������£��������ϴ��ἰ����Ȼ�����Ȳʡ�\n");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 31:
		tell_room(env, "$HIG���ϴ��������������ѶϢ�������Ļ�ŭ�ţ������������Ź�ƶ�ˣ�����װ������̽���ǡ�");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 32:
		tell_room(env, "$HIG�Ÿ���һ���飬�ֹ������죬���һ��������翷��̽��");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 33:
		tell_room(env, "$HIG��һ����ĳ���Լ��׶������ˣ������Ź�Ȼ�����ز������Ҳ���١�");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 34:
		tell_room(env, "$HIG˵Ҳ���������ǵ����չ���ȥ�쿴��˭Ҳ���ҷŵ�̽������ҽ������Σ�Ψ��ײ�����ˡ�");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 35:
		tell_room(env, "$HIG�������ڹ�����֮�У����Ǹ�һ��Ůͯײ���ˡ���Ů�޶��ƺ��Ǹ�Ѿ��֮�࣬��ͻȻ̧ͷ����һ�����ܲ������������˸����档");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 36:
		tell_room(env, "$HIG�������й¶�˻��ܣ�����ǰȥ��ʩչ���÷������뽫��ץס����ʱ����˦��������Ҫ�ˡ�");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 37:
		tell_room(env, "$HIG���չ�����Щ���̫̫������������ָ���书��������ͬС�ɡ�");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 38:
		tell_room(env, "$HIG���Ǹ�ССŮͯ��ֻ��Ҳʮ���˵á������³���ǰȥ����֪�Ǿ���һ��֮�١���");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 39:
		tell_room(env, "$HIR\n������΢΢��������Ȼ��ʱ��������֮�����˿̻�˼��������¡�\n�����ۼ������°�Ȼ������ô��������翷�����������ʲôΣ�ѣ���Ҳ����Ϊ�ġ�\n�������ϴ��Ȼ������翷��϶��֣���˵��ʵ�ƴ��ˣ��������գ�ȴҲ����ǵ�������ˡ�\n ");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 40:
		tell_room(env, "$HIGֻ�����ϴ����˵������֪��������֪��������һ������Ů�޶���ͷ������ץס���ı۰�....");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 41:
		tell_room(env, "$HIG�����������ܣ�����һ�Σ��㼴����ȫ��û���������ȴ��һ���书Ҳ�ޡ�");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 42:
		tell_room(env, "$HIG��ʱ�Ҵ�ϲ������һ��֮�£���ֻ�������ޱȡ�");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 43:
		tell_room(env, "$HIG���¸�λ��Ц�������Լ����Լ�����Ů�޶����ˣ����ⲻ���������ϴ���Щ��Ҳ���ˡ�");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 44:
		tell_room(env, "$HIR\n˵�������Ⱥ�з���һ��Ц������������Ϊ֮һ�ɡ�\n���ϴ��伥���Լ���С�������˾�֪����ʵ���Ǹ��£��ҵ���翷��ϳ������ˣ����ǵ���֮�£�\n ");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 45:
		tell_room(env, "$HIG���ϴ�תͷ����������˵���������������ز�������ǧ����ȷ���ˡ�");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 46:
		tell_room(env, "$HIG����Ҫ�������ѣ�ֻ�й�����������������һ����");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 47:
		tell_room(env, "$HIG����������Ŀǰ�Ƿ��ѻ�ȥ��翷����չ��������޷�֪������������ֹ��Ҫ���Һϼƺϼơ�");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 48:
		tell_room(env, "$HIR\n���ϴ�һ���֣�������һ������һֻ��ɫ����������ǰ������������ǰ��\n���ϴ�⿪��������������������һ�࣬����¶��һ�����������˶��ǡ�������һ����ֻ������������С���Ǹ�Ůͯ��\n");
		env->add("lj/taolun",1);
		me->call_out(do_tielao, 1);	
		me->call_out(do_taolun, 1);	
		break;
	case 49:
		tell_room(env, "$HIG���ϴ��������ĵ������Ů���ޣ�������ĳ�˴���翷����������ġ�");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 50:
		tell_room(env, "$HIR\n�������������������ϴ��˲��𣡡���������Ӣ�ۺú���������ʮ��������ʮ����Ⱥ�ɣ��������ϴ���ף���\n���˻������У�������һ��������ѽѽ�Ŀ�������Ůͯ˫�ְ������ϣ����ض��ޡ�\n");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 51:
		tell_room(env, "$HIG���ϴ���������ڼ��ֵܣ�����ȡ�����У�ÿ������Ů���޿���һ��������һ����");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 52:
		tell_room(env, "$HIG��Ů���������С�����Ǹ��ưͣ��վ�����翷�����");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 53:
		tell_room(env, "$HIG�����ĵ�ͷ�ȹ��������ϵ�Ѫ���Ӵ˸���翷��Ʋ�������������Ҫ���������⣬��Ҳ��������η�������ˡ�");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 54:
		tell_room(env, "$HIR\n��һ˵�꣬�������ͷ�����֡�\n$HIGһ���˵������е����������õ���ˣ������ѪΪ�ˣ��Ӵ��н����ˣ����������յ����ˡ���");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 55:
		tell_room(env, "$$HIR\n\n\n���ϴ�����ͷ�����е��������ϴ��һ�����֣����ӵ����������ڲ����е�Ůͯ������ȥ��\n\n\n");
		env->add("lj/taolun",1);
		me->call_out(do_taolun, 1);	
		break;
	case 56:
		tell_room(env, "$HIR���������ϴ���������������Ȼ�������չ����ˣ������ܲ��ȡ���");
		env->add("lj/taolun",1);
		DTItemList * list = env->Get_ItemList();  
		POSITION p = list->GetHeadPosition(); 
		CChar * tielao;
		while(p) 
		{ 
			CContainer * obj = list->GetNext(p);
			if(! obj->is_character()) continue; 
			tielao = (CChar *)obj;  
			if(EQUALSTR(tielao->querystr("name"), "Ůͯ"))
			{
				tielao->set_weight(10000);
				break;
			}
		}
		me->call_out(do_jiouren, 5);	
		break;
	}
}

static void do_jiouren(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env=me->environment();
	DTItemList * list = env->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	CChar * tielao;
	CChar * target;
	if(env->query("no_move"))
		env->del("no_move");
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		tielao = (CChar *)obj;  
		if(userp(tielao))
		{
			if(tielao->query("lj/renwu6"))
				target = (CChar *)obj;  
			continue;
		}
		if(EQUALSTR(tielao->querystr("name"), "Ůͯ"))
		{
			tell_room(env, "$HIR�������Ȼһ����ֻ��Ѫ��һ���������е�Ůͯ��������һ���ҽУ������ĵ�����ȥ��");
			env->set("lj/lost",1);
			env->del("no_fight");
			destruct(tielao);
			break;
		}
	}
	if(env->query("lj/lost"))
	{
		CChar * fighter = (CChar *)env->Present(param1);
		if(fighter)	
		{
			fighter->set("lj/renwu_lost",1);
			fighter->del("lj/renwu6");
			fighter->del("lj/renwu5");
			fighter->del("lj/renwu55");
			tell_room(env, "$HIR����Ůͯ�����ĵ��£�����ĺ�Ȼ��������ʹ���·�����ʧȥ�����˰�ı�����");
		}
		me->call_out(do_die, 1);
	}
	else
	{
		tell_room(env, "$HIR����������ȣ���ʲô�ˣ����������ɴ�ᵷ�ң��������£���");
		env->set("lj/win",1);
		env->del("no_fight");

		target->add("combat_exp",5000);
		target->UpdateMe();
		tell_object(target, "\n\n$HIR������ˡ����ɴ���¾�Ůͯ�������񣬻����5000��ľ��齱����\n\n");
		target->set("lj/renwu7",1);
		target->del("lj/renwu6");
		target->del("lj/renwu5");
		
		((CUser *)me)->Ready_PK();
		((CUser *)target)->Ready_PK();
		target->kill_ob(me);	
		me->kill_ob(target);
	}
}

static void do_tielao(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * env=me->environment();
	CNpc * tielao = load_npc("lj_tielao");
	tielao->set_name("Ůͯ","nv tong");
	tielao->set_weight(50000000);
	tielao->move(env);
}


NPC_END;




